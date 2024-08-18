//
//  main.cpp
//  Tree Diameter
//
//  Created by Yousef on 29.04.20.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<long long> dist;
vector<bool> visited;
long long ma = 0;;
int beg = 0;


void dfs (int node)
{
    visited[node] = true;
    
    for(auto a: adj[node])
    {
        if(!visited[a])
        {
            dist[a] = dist[node] + 1;
            if(dist[a] > ma)
            {
                ma = dist[a];
                beg = a;
            }
            dfs(a);
        }
    }
}



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a, b;
    cin>>n;
    
    adj = vector<vector<int>> (n + 1);
    dist = vector<long long> (n + 1, 0);
    visited = vector<bool> (n + 1, false);
    
    for(int i = 0; i < n - 1; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);
    ma = 0;
    dist = vector<long long> (n + 1, 0);
    visited = vector<bool> (n + 1, false);
    dfs(beg);
    cout<<ma;
    
    return 0;
}
