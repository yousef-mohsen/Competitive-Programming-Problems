//
//  main.cpp
//  Monsters
//
//  Created by Yousef on 10.03.20.
//  Copyright © 2020 Yousef. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int start, end;
int inf = 1e8;
vector<int> *adj;
queue<int> q;
vector<bool> visited;
vector<int> dist;
vector<int> parent;

void clear( queue<int> &q )
{
   queue<int> empty;
   swap( q, empty );
}

void bfs (int node)
{
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        
        if(dist[top] > dist [start])
        {
            clear(q);
            break;
        }
        
        for(auto n: adj[top])
        {
            if(!visited[n])
            {
                
                dist[n] = dist[top] + 1;
                parent[n] = top;
                q.push(n);
                visited[n] = true;
                
                
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    freopen("test_input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    int n,m;
    int start;
    cin>>n>>m;
    vector<int> monsters;
    vector<int> boundries;
    adj = new vector<int>[n * m + 1];
    
   
    vector<int> ans;
    
    
    vector <vector <char>> graph (n + 1, vector<char> (m + 1));
    
    for(int i = 1; i <= n; i++)
    {
        for(int k = 1; k <= m; k++)
        {
            cin>>graph[i][k];
            if(graph[i][k] == 'M')
            {
                monsters.push_back(m * (i-1)+ k);
                
            }
            if((i == 1|| i ==n || k == 1 || k ==m) && graph[i][k] == '.')
            {
                boundries.push_back((i-1) * m + k);
            }
            
            if(graph[i][k] != '#' )
            {
                if(i > 1)
                {
                    if(graph[i - 1][k] != '#')
                    {
                        adj[m * (i-1)+ k].push_back(m * (i-2)+ k);
                        adj[m * (i-2)+ k].push_back(m * (i-1)+ k);
                    }
                }
                if(k>1)
                {
                    if(graph[i][k - 1] != '#')
                    {
                        adj[m * (i-1)+ k].push_back(m * (i-1)+ k -1);
                        adj[m * (i-1)+ k -1].push_back(m * (i-1)+ k);
                    }
                    
                }
                    if(graph[i][k] == 'A')
                {
                    start = m*(i-1) + k;
                }
            }
        }
        
    }
 
    

    for(auto u : boundries)
    {
        parent = vector<int>(n * m + 1);
        visited = vector<bool>(n * m + 1,false);
        dist = vector <int> (n * m + 1,inf
                             );
        visited[u] = true;
        q.push(u);
        dist[u] = 0;
        bfs(u);
        int distance = dist[start] - dist [u];
        
        int i;
        
        for(i = 0; i < monsters.size(); i++)
        {
            if(dist[monsters[i]] - dist[u] <= distance)
            {
                
                break;
            }
                
        }
        if(i == monsters.size())
        {
            cout<<"YES"<<"\n";
            cout<<dist[start]<<"\n";
            
            while(start != u)
            {
                ans.push_back(start);
                start = parent[start];
            }
            ans.push_back(u);
            for(int i = 1; i< ans.size(); i++)
            {
                int value = ans[i] - ans [i - 1];
                if(value == 1)
                {
                    cout<<'R';
                }
                else if (value == -1)
                {
                    cout<<'L';
                }
                else if(ans[i] > ans[i-1])
                {
                    cout<<'D';
                }
                else
                {
                    cout<<'U';
                }
            }
            return 0;
        }
        
    }
    if(boundries.size() == 0 && monsters.size() == 0)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    
    return 0;
}
