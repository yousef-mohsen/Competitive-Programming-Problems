//
//  main.cpp
//  Subordinates
//
//  Created by Yousef on 24.03.20.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<long long> sub;
vector<bool> visited;

void dfs(int node)
{
    for(auto e: adj[node])
    {
        
        if(!visited[e])
        {
            sub[node] += 1;
            visited[e] = true;
            dfs(e);
            sub[node] += sub[e];
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, e;
    cin>>n;
    
    adj = vector<vector<int>> (n + 1);
    sub = vector<long long> (n + 1, 0);
    visited = vector<bool> (n + 1, false);
    
    for(int i = 2; i <= n; i++)
    {
        cin>>e;
        adj[e].push_back(i);
    }
    
    for(int i = 1; i<=n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            dfs(i);
            
        }
    }
    
    for(int i = 1; i <= n; i ++)
    {
        cout<<sub[i]<<" ";
    }
    
    
    
    return 0;
}
