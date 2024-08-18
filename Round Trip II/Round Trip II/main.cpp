//
//  main.cpp
//  Round Trip II
//
//  Created by Yousef on 22.03.20.
//

#include <iostream>
#include <vector>
#include<stack>
using namespace std;

stack<int> s;
vector<vector<int>> adj;
vector<bool> visited;
vector<long long > dist;
vector<int> parent;


void dfs(int node)
{
    for(auto v: adj[node])
    {
        if(visited[v] && parent[v]!= node && (dist[node]-dist[v] >=1) )
        {
            s.push(v);
            do{
                s.push(node);
                node = parent[node];
            }while(node != v);
            s.push(v);
            cout<<s.size()<<"\n";
            
            while(!s.empty())
            {
                cout<<s.top()<<" ";
                s.pop();
            }
                exit(0);
            }
        else if (!visited[v]){
            
            visited[v] = true;
            dist[v] = dist[node] + 1;
            parent[v] = node;
            dfs(v);
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    cin>>n>>m;
    adj = vector<vector<int>> (n + 1, vector<int>());
    
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    visited =  vector<bool>(n + 1, false);
    dist = vector<long long >(n + 1, 0);
    parent = vector<int>(n + 1);
    
    
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dist[i] = 0;
            visited[i] = true;
            dfs(i);
        }
    }
    
    cout<<"IMPOSSIBLE";

    return 0;
}
