//
//  main.cpp
//  Pizzeria Queries
//
//  Created by Yousef on 29.01.21.
//
 
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
ll si;
void update(ll p, ll v, vector<ll> & tree)
{
    p += si - 1;
    tree[p] = v;
    
    for(p/=2; p >= 1; p/=2)
    {
        tree[p] = min(tree[2 * p], tree[2 * p + 1]);
    }
}
ll query(ll a, ll b, ll k, ll x, ll y, vector<ll> & tree)
{
    if(y < a || b < x)
        return 1e13;
    
    if(a <=x && y <= b)
        return tree[k];
    ll d = (x + y) / 2;
    
    return min(query( a, b, 2 * k,  x, d, tree), query( a, b, 2 * k + 1,  d + 1, y, tree));
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, q, c, type, k, x;
    cin>>n>>q;
    
    for(int i = 0; i <= 18; i++)
        if((1<<i) >= n)
        {
            c = i;
            break;
        }
    
    si = (1<<c);
    vector<ll> d (2 * si + 1, 1e18);
    vector<ll> s (2 * si + 1, 1e18);
    vector<ll> v(n + 1);
    
    for(int i = 1; i <= n; i++)
    {
        cin>>v[i];
        update(i, v[i] + i, s);
        update(i, v[i] - i, d);
        
    }
        
    while(q--)
    {
        cin>>type;
        if(type == 1)
        {
            cin>>k>>x;
            v[k] = x;
            update(k, x + k, s);
            update(k, x - k, d);
        }
        else{
            cin>>x;
            ll m = query(1, max((x - 1), 1LL), 1, 1, si, d) + x;
            m = min(m ,query(min(x + 1, si), si, 1, 1, si, s) - x);
            m = min(m, v[x]);
            cout<<m<<"\n";
            }
    }
    return 0;
}
