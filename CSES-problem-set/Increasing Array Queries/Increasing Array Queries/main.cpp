//
//  main.cpp
//  Increasing Array Queries
//
//  Created by Yousef on 31.01.21.
//
 
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
 
 
 
typedef long long ll;
ll  si, n, q, ma = 1e18;
vector<ll> t, v, k;
 
 
tuple<ll, ll, ll> query (ll a, ll b, ll p, ll x, ll y)
{
    if(y < a || b < x)
        return make_tuple(0,0,0);
    if(a<=x && y<=b)
        return make_tuple(k[p],v[p],t[p]);
    ll d = (x + y)/2;
    auto f = query (a, b, 2 * p, x, d);
    auto s = query (a, b, 2 * p + 1, d + 1, y);
    tuple<ll,ll,ll> ans;
    get<0>(ans) = get<0>(f) + get<0>(s);
    get<1>(ans) = max(get<1>(f), get<1>(s));
    get<2>(ans) = get<2>(f) + get<2>(s);
    if(get<1>(f) > get<1>(s))
    {
        get<2>(ans)+= get<0>(s) *(get<1>(f) - get<1>(s));
    }
        return ans;
    
}
 
void update(ll p, ll value)
{
    p += si - 1;
    t[p] = 0;
    v[p] = value;
    k[p] = 1;
    ll temp = p;
    for(p/=2; p >= 1; p/=2)
    {
        k[p] +=1;
        if(v[p] < value)
            v[p] = value;
        else
        {
            t[p] += v[p] - value;
        }
        temp = p;
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin>>n>>q;
    ll c, a, b;
    for(int i = 0; 1<= 18; i++)
    {
        if((1<<i) >=n)
        {
            c = i;
            break;
        }
    }
    si = (1<<c);
    t.resize(2 * si + 1, 0);
    v.resize(2 * si + 1, 0);
    k.resize(2 * si + 1, 0);
    
    for(int i = 1; i <= n; i++)
    {
        cin>>c;
        update(i, c);
    }
    while(q--)
    {
        cin>>a>>b;
        auto ans = query (a, b, 1, 1, si);
        cout<<get<2>(ans)<<"\n";
    }
    return 0;
}
