//
//  main.cpp
//  Distinct Routes
//
//  Created by Yousef on 26.12.20.
//
 
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
 
using namespace std;
int n, flow;
bool f = false;
vector<vector<int>> adj;
vector<pair<int, int>> edge;
vector<bool> visited;
vector<bool> taken;
#include <stack>
stack<int> ans;
 
void dfs(int u)
{
    visited[u] = true;
    
    if (u == n)
    {
        flow += 1;
        f = true;
        return;
    }
    for(auto v: adj[u])
    {
        if(!visited[edge[v].first] && edge[v].second == 1)
        {
            dfs(edge[v].first);
            
            if(f)
            {
                edge[v].second = 0;
                if(v & 1)
                {
                    edge[v + 1].second = 1;
                }
                else
                {
                    edge[v - 1].second = 1;
                }
                return;
            }
            visited[u] = false;
        }
    }
}
void dfs2(int u)
{
    visited[u] = true;
    if (u == n)
    {
        f = true;
        ans.push(u);
        return;
    }
    for(auto v: adj[u])
    {
        if((v & 1) && !taken[v] && !visited[edge[v].first] && edge[v].second == 0)
        {
            dfs2(edge[v].first);
            if(f)
            {
                ans.push(u);
                taken[v] = true;
                return;
            }
            visited[u] = false;
       }
    }
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int m, a, b;
    cin>>n>>m;
    adj = vector<vector<int>> (n + 1);
    edge = vector<pair<int, int>>(2 * m + 1);
    taken = vector<bool> (2 * m + 1);
    int counter = 1;
    
    for(int i = 1; i <= m; i++)
    {
        cin>>a>>b;
        adj[a].push_back(counter);
        adj[b].push_back(counter + 1);
        edge[counter] = {b, 1};
        edge[counter + 1] = {a, 0};
        counter += 2;
        
    }
    int temp;
    do {
        temp = flow;
        f = false;
        visited = vector<bool> (n + 1, false);
        dfs(1);
       
    }while(temp != flow);
    cout<<flow<<"\n";
    
    do
    {
        f = false;
        visited = vector<bool> (n + 1, false);
        dfs2(1);
        if(ans.size() > 0)
            cout<<ans.size()<<"\n";
        while(ans.size() > 0)
        {
            temp = ans.top();
            cout<<temp<<" ";
            ans.pop();
        }
        cout<<"\n";
    }while(f);
 
 
    return 0;
}
