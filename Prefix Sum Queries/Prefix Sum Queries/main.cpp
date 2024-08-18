//
//  main.cpp
//  Prefix Sum Queries
//
//  Created by Yousef on 28.01.21.
//
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll si, ans, total;
vector<ll> p, s, t, sub;

void query (ll a, ll b, ll k, ll x, ll y)
{
    if(a > y|| b < x)
        return;
    if(a <= x && y <= b)
    {
        
        ans = max(ans, total + p[k]);
        total += t[k];
        return;
    }
    ll d = (x + y)/2;
    query (a, b, 2 * k, x, d);
    query (a, b, 2 * k + 1, d + 1, y);
}

void update(ll pos, ll value)
{
    pos += si - 1;
    p[pos] = value;
    t[pos] = value;
    
    for(pos/= 2; pos>=1; pos/=2)
    {
        t[pos] = t[2 * pos] + t[2 * pos + 1];
        p[pos] = max(p[2 * pos],  t[2 * pos] + p[2 * pos + 1]);
    }
    
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m, c, x, k, type;
    cin>>n>>m;
    for(int i = 0; i <= 18; i++)
        if((1<<i) >= n)
        {
            c = i;
            break;
        }
    si = (1<<c);
    p.resize(2 * si + 1, 0);
    t.resize(2 * si + 1, 0);
    
    for(int i = 1; i <= n; i++)
    {
        cin>>x;
        update(i, x);
    }
    for(int i = 1; i <= m; i++)
    {
        cin>>type>>k>>x;
        if(type == 1)
        {
            update(k, x);
        }
        else
        {
            ans = 0;
            total = 0;
            query(k, x, 1, 1, si);
            cout<<ans<<"\n";
            
        }
        
    }
    return 0;
}
