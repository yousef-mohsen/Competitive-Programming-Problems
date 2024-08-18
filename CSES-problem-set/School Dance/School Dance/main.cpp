//
//  main.cpp
//  School Dance
//
//  Created by Yousef on 26.12.20.
//

#include <iostream>
#include <vector>
#include <utility>

using namespace std;
vector<vector<int>> adj;
vector<pair<int, int>> edge;
vector<bool>visited;

int n, e, flow;
bool f = false;

void dfs(int u)
{
    visited[u] = true;
    if(u == e){
        f = true;
        flow ++;
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
                    edge[v + 1].second = 1;
                else
                    edge[v - 1].second = 1;
                return;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int m, k, a, b;
    cin>>n>>m>>k;
    e = 2 * n + 1;
    adj = vector<vector<int>>(2 * n + 2);
    edge = vector<pair<int, int>> ((k + 2 * n + 1)* 2);
    visited = vector<bool> (2 * n + 2);
    
    int counter = 1;

    for(int i = 1; i <= k; i++)
    {
        cin>>a>>b;
        adj[a].push_back(counter);
        adj[b + n].push_back(counter + 1);
        edge[counter] = {b + n, 1};
        edge[counter + 1] = {a, 0};
        counter += 2;
    }
    
    for(int i = 1; i <= n; i++)
    {
        adj[0].push_back(counter);
        adj[i].push_back(counter + 1);
        edge[counter] = {i, 1};
        edge[counter + 1] = {0, 0};
        adj[i + n].push_back(counter + 2);
        //adj[0].push_back(i + n);
        edge[counter + 2] = {e, 1};
        counter += 4;
        
    }
    int temp;
    do{
        temp = flow;
        visited = vector<bool> (2 * n + 2);
        f = false;
        dfs(0);
    }while(temp != flow);
    
    cout <<flow<<"\n";
    for(int i = 1; i <= n; i++)
    {
        for(auto v: adj[i])
            if(v & 1 && edge[v].second == 0)
            {
                cout<<i<<" "<<edge[v].first - n<<"\n";
                
            }
                
        
    }
    return 0;
}
