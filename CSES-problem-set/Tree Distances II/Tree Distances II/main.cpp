//
//  main.cpp
//  Tree Distances II
//
//  Created by Yousef on 25.09.20.
//

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll counter = 0;
vector<ll> p;
vector<ll> c;
vector<ll> d;
vector<bool> visited;
vector<ll> order;
vector<vector<ll>> adj;


void dfs(ll v)
{
    visited[v] = true;
    for(auto u : adj[v])
    {
        if(!visited[u])
        {
            order[counter] = u;
            counter++;
            p[u] = v;
            dfs(u);
            d[v] += c[u] + d[u];
            c[v] +=c[u];
        }
    }
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, a, b;
    cin>>n;
    adj = vector<vector<ll>> (n + 1, vector<ll>());
    visited = vector<bool> (n + 1, false);
    p = vector<ll> (n + 1);
    c = vector<ll> (n + 1, 1);
    d = vector<ll> (n + 1, 0);
    order = vector<ll> (n);
    
    for(int i = 1; i < n; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visited[1] = true;
    dfs(1);
    
    for(auto u: order)
    {
        d[u] += d[p[u]] - d[u] - c[u] + (c[p[u]] - c[u]) ;
        c[u] += c[p[u]] - c[u];
    }
    
    for(int i = 1; i <= n; i++)
        cout<<d[i]<<" ";
    
    return 0;
}
