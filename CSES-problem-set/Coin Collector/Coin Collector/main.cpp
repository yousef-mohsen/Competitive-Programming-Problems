//
//  main.cpp
//  Coin Collector
//
//  Created by Yousef on 07.11.20.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef long long ll;
vector<vector<ll>> adj;
vector<vector<ll>> adj2;
vector<ll> value;
vector<bool> visited;
vector<ll> group;
vector<ll> group_sum;
vector<ll> sum;
stack<ll> s;

void dfs3(ll a)
{
    visited[a] = true;
    sum[a] = group_sum[a];
    for (auto t: adj2[a])
    if(!visited[t])
    {
        dfs3(t);
        sum[a] = max(sum[a], group_sum[a] + sum[t]);
    }
    else
    {
      sum[a] = max(sum[a], group_sum[a] + sum[t]);
    }
    
}
void dfs(ll a)
{
    visited[a] = true;
    for (auto t: adj[a])
        if(!visited[t])
            dfs(t);
    s.push(a);
}

void dfs2(ll n, ll c)
{
    visited[n] = true;
    group [n] = c;
    group_sum[c] += value[n];
    for(auto t: adj2[n])
    {
        if(!visited[t])
        {
            dfs2(t, c);
        }
        
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n, m, a, b;
    cin>>n>>m;
    adj = vector<vector<ll>> (n + 1, vector<ll>());
    value = vector<ll> (n + 1);
    visited = vector<bool> (n + 1, false);
    group = vector<ll> (n + 1);
    group_sum = vector<ll> (n + 1, 0);
    sum = vector<ll> (n + 1, 0);
    
    for(int i = 1; i <= n; i++)
        cin>>value[i];
    
    for (int i = 1; i <= m; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i = 1; i <= n; i++)
        if(!visited[i])
            dfs(i);
    
    ll counter = 0;
    visited = vector<bool> (n + 1, false);
    adj2 = vector<vector<ll>> (n + 1, vector<ll>());
    for(int i = 1; i <= n; i++)
    {
        for(auto t: adj[i])
            adj2[t].push_back(i);
    }
    
    while(s.size() > 0)
    {
        ll t = s.top();
        s.pop();
        if(!visited[t])
        {
            dfs2(t,++counter);
        }
        
    }
    adj2 = vector<vector<ll>> (n + 1, vector<ll>());
    visited = vector<bool> (n + 1, false);
    
    for(int i = 1; i <= n; i++)
    {
        for(auto a: adj[i])
        {
            if(group[a] != group[i])
                adj2[group[i]].push_back(group[a]);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
            dfs3(i);
    }
    ll ma = -1;
    for(int i = 1; i <=n; i++)
        if(sum[i]> ma)
            ma = sum[i];
    
    cout<<ma;
    return 0;
}
