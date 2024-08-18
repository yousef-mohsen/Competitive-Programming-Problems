//
//  main.cpp
//  Teleporters Path
//
//  Created by Yousef on 30.12.20.
//
 
#include <iostream>
#include <vector>
using namespace std;
 
vector<vector<int>> adj;
vector<bool> visited;
vector<int> edge;
vector<int> ans;
 
void dfs(int u)
{
    for(auto v: adj[u])
    {
        if(!visited[v])
        {
            visited[v] = true;
            dfs(edge[v]);
        }
    }
    ans.push_back(u);
}
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    cin>>n>>m;
    adj = vector<vector<int>> (n + 1);
    visited = vector<bool> (m + 1, false);
    edge = vector<int>(m + 1);
    vector<int> in (n + 1, 0);
    vector<int> out (n + 1, 0);
    
    for(int i = 1; i <= m; i++)
    {
        cin>>a>>b;
        adj[a].push_back(i);
        edge[i] = b;
        out[a] ++;
        in[b] ++;
    }
    if(out[1] - 1 != in[1] || in[n] != out[n] + 1 )
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for (int i = 2; i < n; i++)
    {
        if(in[i] != out[i])
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    
    for(int i = ans.size() - 1; i >= 0; i--)
    {
        cout<<ans[i]<<" ";
    }
 
    return 0;
}
