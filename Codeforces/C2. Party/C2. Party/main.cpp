//
//  main.cpp
//  C2. Party
//
//  Created by Yousef on 11.08.20.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

int id = 0;
vector<vector<int>> adj;
vector<pair<int , int>> h;
vector<bool> visited;
vector <set<int>> groups;



void dfs(int n)
{
        for(auto k: adj[n])
        {
            if(!visited[k])
            {
                visited[k] = 1;
                groups[id].insert(k);
                dfs(k);
            }
        }
    
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, k, m, u, v, size = 0;
    
    cin>>n>>k;
    
    adj = vector<vector<int>> (n + 1);
    visited = vector <bool> (n + 1);
    groups = vector<set<int>> (n + 1);
    
    for(int i =0; i < k; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }
    
    cin>>m;
    h = vector <pair<int,int>>();
    
    for(int i = 1; i<=m; i++)
    {
        cin>>u>>v;
        h.push_back(make_pair(u,v));
        
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            id ++;
            groups[id].insert(i);
            visited[i] = 1;
            dfs(i);
        }
    }
    
    
    for(int i = 1; i < groups.size(); i++)
    {
        bool f = true;
        for(auto m: h)
        {
            if(groups[i].count(m.first) == 1 && groups[i].count(m.second) == 1)
                {
                    f = false;
                    groups.erase(groups.begin() + i);
                    i--;
                    break;
                }
        }
    }
    
    for(auto k: groups)

    {
        size = max(size, int(k.size()));
    }
    cout<<size;
    
    
    return 0;
}
