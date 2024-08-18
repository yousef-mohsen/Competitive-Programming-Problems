//
//  main.cpp
//  Flight Routes Check
//
//  Created by Yousef on 16.09.20.
//

#include <iostream>
#include <vector>

using namespace std;

void dfs(int n, vector<vector<int>> & adj, vector<int> & visited)
{
    visited[n] = true;
    for(auto a: adj[n])
        if(!visited[a])
            dfs(a, adj, visited);
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    cin>>n>>m;
    vector<vector<int>> adj (n + 1);
    vector <int> visited (n + 1, false);
    
    for(int i = 1; i <= m; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    dfs(1, adj, visited);
    
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            cout<<"NO"<<"\n";
            cout<<1<<" "<<i;
            return 0;
        }
    }
    vector<vector<int>> adj2 (n + 1);
    vector <int> visited2 (n + 1, false);
    
    for(int i = 1; i <=n ; i++)
    {
        for(auto k: adj[i])
            adj2[k].push_back(i);
    }
    dfs(1, adj2, visited2);
    
    for(int i = 1; i <= n; i++)
       {
           if(!visited2[i])
           {
               cout<<"NO"<<"\n";
               cout<<i<<" "<<1;
               return 0;
           }
       }
    
    cout<<"YES";
    
    return 0;
}
