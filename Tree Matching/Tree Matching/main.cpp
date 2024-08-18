//
//  main.cpp
//  Tree Matching
//
//  Created by Yousef on 24.03.20.
//

#include <iostream>
#include <vector>
using namespace std;
int counter = 0;
vector<bool> visited;
vector<bool> marked;
vector<vector<int>> adj;

void dfs(int node)
{
    if (visited[node])
        return;
    
    visited[node] = true;
    
    for(auto n: adj[node])
    {
        dfs(n);
    }
   
    if(!marked[node])
    {
        for(auto n: adj[node])
        {
           if(!marked[n])
           {
               marked[n] = true;
               marked[node] = true;
               counter ++;
           }
       }
    }

        
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a, b;
    cin>>n;
    adj = vector<vector<int>> (n + 1);
    
    visited = vector<bool>(n + 1, false);
    marked = vector<bool>(n + 1, false);
    
    for(int i = 0; i < n - 1; i++)
    {
        cin>>a>>b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    cout<<counter;
    return 0;
}
