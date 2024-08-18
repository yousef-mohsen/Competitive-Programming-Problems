//
//  main.cpp
//  Finding a Centroid
//
//  Created by Yousef on 02.02.21.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent, c;

void dfs(int u)
{
    visited[u] = true;
    for(auto v: adj[u])
        if(!visited[v])
        {
            parent[v] = u;
            dfs(v);
            c[u] += c[v];
        }
    
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, a, b;
    cin>>n;
    visited.resize(n + 1, false);
    parent.resize(n + 1, 0);
    c.resize(n + 1, 1);
    adj.resize(n + 1, vector<int>());
    for(int i = 1; i < n; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    b = 1;
    int i = 0;
    int temp = 0;
    while(true)
    {
        temp = b;
        for(i = 0; i < adj[b].size(); i++)
        {
            if(adj[b][i] != parent[b] && c[adj[b][i]] > n/2)
            {
                b = adj[b][i];
                break;
            }
        }
        if(i == adj[temp].size())
            break;
    }
    cout<<b<<"\n";

    
    
    return 0;
}
