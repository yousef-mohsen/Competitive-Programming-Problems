//
//  main.cpp
//  Road Reparation
//
//  Created by Yousef on 16.09.20.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

typedef long long  ll;
using namespace std;

ll find (ll x, vector <ll>& v)
{
    if(v[x] == x)
        return x;
    
    return  v[x] = find(v[x], v);
}

void unite (ll x, ll y, vector <ll>& size, vector <ll>& link)
{
    x = find (x, link);
    y = find (y, link);
    
    if(size[x] < size[y])
        swap(x ,y);
        
    size[x] += size[y];
    link [y] = x;
}

bool same(ll x, ll y, vector<ll> & link)
{
    return find(x, link) == find (y, link);
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m, a, b, c, sum = 0;
    cin>>n>>m;
    vector <tuple<ll, ll , ll>> e;
    vector<ll> link (n + 1);
    vector<ll> size (n + 1);
    
    for(int i = 1; i <= n; i++)
    {
        link[i] = i;
        size[i] = 1;
    }
    
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        e.push_back({c, a, b});
    }
    sort(e.begin(), e.end());
    
    for (auto t : e)
    {
        a = get<1>(t);
        b = get<2>(t);
        c = get<0>(t);
        
        if(!same(a, b, link))
        {
            sum += c;
            unite(a, b, size, link);
        }
    }
    ll s = find (1, link);
    for(int i = 2; i<=n; i++)
    {
        if(find (i, link) != s)
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    
    cout<<sum;
    
    
    return 0;
}
