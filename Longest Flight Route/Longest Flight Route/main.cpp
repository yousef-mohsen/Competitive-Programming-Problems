//
//  main.cpp
//  Longest Flight Route
//
//  Created by Yousef on 22.03.20.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> child;
vector<int> dist;

void dfs(int node)
{
    for(auto v: adj[node])
    {
        if(!visited[v])
        {
            visited[v] = true;
            dfs(v);
            if(dist[v] + 1 > dist[node] && dist[v] >= 0)
            {
                dist[node] = dist[v] + 1;
                child[node] = v;
            }
        }
        else{
                if(dist[node]< dist[v]+1)
                {
                    dist[node] = dist[v] + 1;
                    child[node] = v;
                }
        }
    }
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    cin>>n>>m;
    
    adj = vector<vector<int>>(n + 1, vector<int>());
    visited = vector<bool> (n + 1, false);
    child = vector<int> (n + 1);
    dist = vector<int> (n + 1, -2);
    
    for (int i = 1; i <= m; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    
    dist[n] = 0;
    dfs(1);
    if(!visited[n])
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    
    int f = 1;
    vector<int> ans;
    
    do{
        ans.push_back(f);
        f = child[f];
    }while(f!= n);
    
    ans.push_back(n);
    cout<<ans.size()<<"\n";
    
    for(auto a: ans)
    {
        cout<<a<<" ";
    }
    
    return 0;
}
