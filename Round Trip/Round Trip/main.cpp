//
//  main.cpp
//  Round Trip
//
//  Created by Yousef on 10.03.20.
//  Copyright © 2020 Yousef. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector <int> * adj;
vector <bool> visited;
vector <long long> dist;
vector <int> parent;

void dfs(int node)
{
    for(auto v : adj[node])
    {
        if(visited[v] && parent[v]!= node)
        {
            if(dist[node] - dist[v] >= 2)
            {
                cout<<dist[node] - dist[v] +2 <<"\n";
                int temp = node;
                while(node!= v)
                {
                    cout<<node<<" ";
                    node = parent [node];
                }
                cout<<v<<" "<<temp;
                exit(0);
            }
        }
        if(!visited[v])
        {
            visited[v] = true;
            dist [v] = dist[node] + 1;
            parent[v] = node;
            dfs(v);
            }
    }
    
}


int main(int argc, const char * argv[]) {
    
    int n, m, a, b;
    cin>>n>>m;
    adj = new vector<int> [n + 1];
    visited = vector<bool>(n + 1, false);
    dist = vector<long long> (n + 1, 0);
    parent = vector<int>(n + 1, 0);
    for(int i = 1; i <= m; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        
    }
    for(int i = 1; i<= n; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            dfs(i);
        }
    }
    
    cout<<"IMPOSSIBLE";
    
    return 0;
}
