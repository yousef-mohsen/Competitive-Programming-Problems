//
//  main.cpp
//  Forest Queries II
//
//  Created by Yousef on 12.01.21.
//
 
#include <iostream>
#include <vector>
 
using namespace std;
typedef long long ll;
vector<vector<ll>> bit;
vector<vector<bool>> g;
ll n;

void add(ll y, ll x, ll v)
{
    
    for(ll y1 = y; y1 <=n + 1; y1 += (y1 & - y1))
        for(ll x1 = x; x1 <=n + 1; x1 += (x1 & - x1))
    {
        bit[y1][x1] += v;
    }
}
 
ll sum (ll y, ll x)
{
    ll ans = 0;
    for(; y > 0; y -= (y & - y))
        for(ll x1 = x; x1 > 0; x1 -= (x1 & - x1))
    {
        ans += bit[y][x1];
    }
    return ans;
}
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll q, counter, t, a , x1, x2, y1, y2;
    char c;
    cin>>n>>q;
    bit.resize(n + 1, vector<ll>(n + 1, 0));
    g.resize(n + 1, vector<bool>(n + 1, 0));
    
    for(int i = 1; i <=n ; i++)
        for(int k = 1; k <=n; k++)
        {
            cin>>c;
            if(c== '*')
            {

                add(i, k, 1);
                g[i][k] = 1;
            }
        }
    for(int i = 1; i <= q; i++)
    {
        cin>>t;
        if(t == 1)
        {
            cin>>y1>>x1;
            if(g[y1][x1])
            {
                add(y1, x1, -1);
                g[y1][x1] = 0;
                
            }
            else
            {
                add(y1, x1, 1);
                g[y1][x1] = 1;
            }
                
        }
        else
        {
            ll ans = 0;
            cin>>y1>>x1>>y2>>x2;
            ans+= sum(y2, x2);
            ans+= sum(y1 - 1, x1 - 1);
            ans-= sum(y1 - 1, x2);
            ans-= sum(y2, x1 - 1);
            cout<<ans<<"\n";
        }
        
    }
 
    
 
    return 0;
}
