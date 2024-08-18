//
//  main.cpp
//  Building Teams
//
//  Created by Yousef on 10.03.20.
//  Copyright © 2020 Yousef. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> * adj;
vector <bool> visited;
vector<int> group;

void dfs(int node, bool color)
{
    visited[node] = true;
    if(color)
    {
        group[node] = 1;
    }
    else
    {
        group [node] = 2;
    }
    
     for (auto v: adj[node])
     {
         if(!visited[v])
         {
             dfs(v, !color);
         }
         if(visited[v])
         {
             if(group[node] == group[v])
             {
                 cout<<"IMPOSSIBLE";
                 exit(0);
             }
         }
     }
}



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    cin>>n>>m;
    
    group = vector<int> (n + 1, 0);
    adj = new vector<int>[n + 1];
    visited = vector <bool>  (n + 1, false);
    
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    
    for(int i = 1; i <= n; i++)
    {
        if(adj[i].size()>0 )
        {
            if(!visited[i])
            dfs(i, true);
        }
        else
        {
            if(!visited[i])
            group[i] = 1;
        }
    }
    for(int i=1; i <= n; i++)
    {
        cout<<group[i]<<" ";
    }
    
    return 0;
}
