//
//  main.cpp
//  Longest Flight Route
//
//  Created by Yousef on 22.03.20.
//

#include <iostream>
#include <vector>
using namespace std;

long long mo = 1e9+7;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> child;
vector<int> dist;
vector<long long> c;

void dfs(int node)
{
    for(auto v: adj[node])
    {
        if(!visited[v])
        {
            visited[v] = true;
            dfs(v);
            c[node] += c[v];
            
            if(c[node] > mo)
            {
                c[node] %= mo;
            }
        
        }
        else{
                c[node] += c[v];
                if(c[node] > mo)
                    {
                        c[node] %= mo;
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
    
    c = vector<long long>(n + 1);
    c[n] = 1;
    dfs(1);
    
    cout<<c[1];
    
    return 0;
}
