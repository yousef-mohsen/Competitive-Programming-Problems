//
//  main.cpp
//  Course Schedule
//
//  Created by Yousef on 22.03.20.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> s;
vector<bool> visited;
vector<vector<int>> adj;
vector<int> parent;

void dfs(int node)
{
    for(auto v: adj[node])
    {
        if(visited[v] && parent[v] == -1)
        {
            cout<<"IMPOSSIBLE";
            exit(0);
        }
        if(!visited[v])
        {
            visited[v] = true;
            parent[v] = node;
            dfs(v);
            s.push(v);
        }
        if(visited[v] && parent[v] == -1)
        {
            parent[v] = node;
        }
    }
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    cin>>n>>m;
    adj = vector<vector<int>>(n + 1, vector<int>());
    visited = vector<bool>(n + 1, false);
    parent = vector<int>(n + 1, -1);
    
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            
            visited[i] = true;
            dfs(i);
            s.push(i);
            parent[i] = 0;
        }
            
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
    
    return 0;
}
