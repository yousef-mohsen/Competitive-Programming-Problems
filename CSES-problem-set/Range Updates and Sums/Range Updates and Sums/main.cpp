//
//  main.cpp
//  Range Updates and Sums
//
//  Created by Yousef on 16.01.21.
//

#include <iostream>
#include <vector>
typedef long long ll;

using namespace std;

vector<ll> s, u, l;
ll n, q, c, si, t, len;
void inc (ll a, ll b, ll k, ll x, ll y, ll value);

void update(ll k, ll type, ll x, ll y, ll value)
{
    ll d = (x + y)/2;
    if(k >= si)
    {
        if(type)
            s[k] = value;
        else
            s[k] += value;
        return;
    }
    
    ll e = min(d - x + 1, len - x - si + 2 );
    if(type)
    {
        u[k] = value;
        l[k] = 0;
        if(x + si - 1 <= len)
        {
            s[k] = value * e;
        }
    }
    else
    {
        if(u[k])
            u[k] += value;
        else
            l[k] += value;
        if(x + si - 1 <= len)
        {
            s[k] += value * e;
        }
        
    }
    if(d + si  <= len)
        {
            ll e = min(y - d , len - d - si + 1);
            s[k] += value * e;
        }

    }
void set (ll a, ll b, ll k, ll x, ll y, ll value, ll type)
{
   if(b < x || a > y)
        return;
  
    if(a <= x  && y <= b)
    {
        update(k, type, x, y, value);
        return;
    }
    ll d = x + y;
    d/= 2;
    
    if(u[k])
    {
        update(2 * k, 1, x, d, u[k]);
        update(2 * k + 1, 1, d + 1, y, u[k]);
        u[k] = 0;
    }
    
    else if(l[k])
    {
        update(2 * k, 0, x, d, l[k]);
        update(2 * k + 1, 0, d + 1, y, l[k]);
        l[k] = 0;
    }
    
    set(a, b, 2 * k, x, d, value, type);
    set(a, b, 2 * k + 1, d + 1, y, value, type);
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
    ll d = (x + y)/2;
   
    if(u[k])
    {
        update(2 * k, 1, x, d, u[k]);
        update(2 * k + 1, 1, d + 1, y, u[k]);
        u[k] = 0;
    }
    else if(l[k])
    {
        update(2 * k, 0, x, d, l[k]);
        update(2 * k + 1, 0, d + 1, y, l[k]);
        l[k] = 0;
    }
        
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
    u.resize(2 * si + 1, 0);
    l.resize(2 * si + 1, 0);
    len = si + n - 1;
    for(int i = 1; i <= n; i++)
    {
        cin>>a;
        set (i, i, 1, 1, si, a, 1);
    }
    
    
    while(q--)
    {
        cin>>t;
        if(t == 1)
        {
            cin>>a>>b>>x;
            set (a, b, 1, 1, si, x, 0);
        }
        else if(t == 2)
        {
            cin>>a>>b>>x;
            set (a, b, 1, 1, si, x , 1);
        }
        else
        {
            cin>>a>>b;
            cout<<sum(a, b, 1, 1,si)<<"\n";
        }
    }

    return 0;
}
