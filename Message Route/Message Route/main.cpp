//
//  main.cpp
//  Message Route
//
//  Created by Yousef on 09.03.20.
//  Copyright © 2020 Yousef. All rights reserved.
//

#include <iostream>
#include <vector>
#include "queue"
#include "stack"
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b, inf = 1e8;
    queue<int> q;
    
    cin>>n>>m;
 
    vector <int> * adj = new vector<int> [n + 1];
    vector<bool> visited(n + 1, false);
    vector <int> distance (n + 1, inf);
    vector <int> parent (n + 1);
    stack <int> path;
    parent[1] = 1;
    distance [1] = 0;
    q.push(1);
    
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited[1] = true;
    
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        
        for(auto u: adj[s])
        {
            if(visited[u])
            {
                continue;
            }
            visited [u] = true;
            distance[u] = distance[s] + 1;
            parent[u] = s;
            if(u == n)
            {
                break;
            }
            q.push(u);
            
            }
    }
    if(distance[n] == inf)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    int i = n;
    while(parent[i] != i)
    {
        path.push(i);
        i = parent[i];
    }
    path.push(1);
    cout<<path.size()<<"\n";
    
    while(!path.empty())
    {
        
        cout<<(path.top())<<" ";
        path.pop();
    }
    
    
    
    return 0;
}
