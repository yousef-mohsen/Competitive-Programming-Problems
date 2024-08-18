//
//  main.cpp
//  Planets and Kingdoms
//
//  Created by Yousef on 17.09.20.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int k = 0;
stack<int> s;

void dfs(int n, vector<bool> & visited, vector<vector<int>> &adj,vector<int> & group)
{
    visited[n] = true;
    group[n] = k;
    for(auto a: adj[n])
        if (!visited[a])
            dfs(a, visited, adj, group);
    s.push(n);
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    cin>>n>>m;
    vector<vector<int>> adj (n + 1);
    vector<vector<int>> adj2 (n + 1);
    vector<bool> visited (n + 1, false);
    vector<bool> visited2 (n + 1, false);
    vector<int> group (n + 1);
    
    while(m--)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }
    
    for(int i = 1; i <=n; i++)
    {
        if(!visited[i])
            dfs(i, visited, adj, group);
    }
    
    while(!s.empty())
    {
        int t = s.top();
        s.pop();
        if(!visited2[t])
        {
            k++;
            dfs(t, visited2, adj2, group);
        }
    }
    
    cout<<k<<"\n";
    for(int i = 1; i <=n; i++)
    {
        cout<<group[i]<<" ";
    }
    
        

    return 0;
}
