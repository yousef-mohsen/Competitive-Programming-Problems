//
//  main.cpp
//  Gray Code
//
//  Created by Yousef on 07.01.21.
//

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<string> v;

void dfs(int u)
{
    visited[u] = true;
    
    cout<<v[u]<<"\n";
    for(auto v: adj[u])
    {
        if(!visited[v])
            dfs(v);
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    set <int> s;
    int n;
    cin>>n;
    int t = (2<<(n - 1));
    v = vector<string>(t);
    visited = vector<bool> (t, false);
    
    adj = vector<vector<int>> (t);
    for(int i = 0; i < t; i++)
    {
        string ss;
        
        for(int c = n - 1; c >= 0; c--)
        {
                if(i & (1<<c))
                    ss+='1';
                else
                {
                    ss+='0';
                }
        }
        v[i] = ss;
    }

    for(int i = 0; i < t; i++)
    {
        for(int c = 0 ; c < n; c++)
        {
            adj[i].push_back(i ^ (1<<c));
        }
    }
    dfs(0);
    
    return 0;
}
