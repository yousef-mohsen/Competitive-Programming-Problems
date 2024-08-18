//
//  main.cpp
//  Polynomial Queries
//
//  Created by Yousef on 22.01.21.
//

#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;

vector<ll> s, z1, z;
ll n, q, c, si, t, len;
void inc (ll a, ll b, ll k, ll x, ll y);

void add(ll k, ll x) {
    k += si - 1;
    s[k] += x;
    for (k /= 2; k >= 1; k /= 2)
    {
           s[k] = s[2*k]+s[2*k+1];
    }
}

void update(ll k, ll x, ll y)
{
    if(k>= si)
        return;
    ll d = (x + y)/2;
    d++;
    ll t = z[2 * k + 1];
    ll t1 = z1[2 * k + 1];
    z1[2 * k]+=z1[k];
    z[2 * k] += z[k];
    
    z1[2 * k + 1]+=z1[k];
    z[2 * k + 1] += z[k];
    z[2 * k + 1] += (d - x) *z1[k];
    s[2 * k]+= (((d - 1 - x) * (d - x))/2) * z1[k];
    s[2 * k] +=z[k] * (d - x);
    t = z[2 * k + 1] - t;
    t1 = z1[2 * k + 1] - t1;
    s[2 * k + 1]+= (y - d + 1) * t;
    s[2 * k + 1]+= (((y - d + 1)*(y - d))/2) * t1;

    return;
}
void inc (ll a, ll b, ll k, ll x, ll y)
{
   if(b < x || a > y)
        return;
  
    if(a <= x  && y <= b)
    {
        z[k] += 1 + x - a;
        z1[k] += 1;
        s[k]+= (1 + x - a) * (y - x + 1) + (((y - x) * (y - x + 1))/2);
        return;
    }
    ll d = x + y;
    d/= 2;
    
   if(z[k] || z1[k])
   {
       update(k, x, y);
       z[k] = 0;
       z1[k] = 0;
   }
    
    inc(a, b, 2 * k, x, d);
    inc(a, b, 2 * k + 1, d + 1, y);
    s[k] = s[2 * k + 1] + s[2 * k];
}

ll sum(ll a, ll b, ll k, ll x, ll y)
{
    if(b < x || a > y)
        return 0;
   if(a <= x  && y <= b)
    {
       return s[k];
    }
    
    if(z[k] || z1[k])
    {
        update(k, x, y);
        z[k] = 0;
        z1[k] = 0;
    }
    
    ll d = (x + y)/2;
 
    return sum(a, b, 2 * k, x, d) + sum(a, b, 2 * k + 1, d + 1, y);
    
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    ll a, b, x;
    
    for(int i = 0; i <= 18; i++)
        if((1<<i) >= n)
        {
            c = i;
            break;
        }
    si = (1<<c);
    s.resize(2 * si + 1, 0);
    z1.resize(2 * si + 1, 0);
    z.resize(2 * si + 1, 0);
    len = si + n - 1;
    for(int i = 1; i <= n; i++)
    {
        cin>>a;
        add(i , a);
    }
    
    
    while(q--)
    {
        cin>>t;
        if(t == 1)
        {
            cin>>a>>b;
            inc(a, b, 1, 1, si);
        }
        else
        {
            cin>>a>>b;
            cout<<sum(a, b, 1, 1,si)<<"\n";
        }
    }

    return 0;
}
