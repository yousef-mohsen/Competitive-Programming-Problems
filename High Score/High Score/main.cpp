//
//  main.cpp
//  High Score
//
//  Created by Yousef on 13.03.20.
//
 
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;


vector<vector<int>> adjlist;
vector<bool> v_dfs ;

void dfs(int n)
{
 if(!v_dfs[n])
 {
     v_dfs[n] = true;
     for(auto e: adjlist[n])
         dfs(e);
 }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    long long inf = -1e13, x;
    
    cin>>n>>m;
    
    vector <tuple<int, int, long long>> adj;
    adjlist = vector<vector<int>> (n + 1, vector<int>());
    vector<long long> dist(n + 1, inf);
    vector <bool> visited (n + 1, false);
    
    
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b>>x;
        adjlist[a].push_back(b);
        adj.push_back({a, b, x});
    }
    
    dist[1] = 0;
    
    for(int i= 0; i< n - 1; i++)
    {
        for(auto e: adj)
        {
            long long distance = dist[get<0>(e)] + get<2>(e);
            if(visited[get<1>(e)])
            {
                if(dist[get<1>(e)] < distance)
                {
                    dist[get<1>(e)] = distance;
                }
            }
            else
            {
                dist[get<1>(e)] = distance;
                visited[get<1>(e)] = true;
            }
        }
    }
    vector<long long> dist_2(dist);
    
    for(auto e: adj)
           {
               long long distance = dist[get<0>(e)] + get<2>(e);
               if(dist[get<1>(e)] < distance)
               {
                   dist[get<1>(e)] = distance;
               }
                   
           }
    
    v_dfs = vector<bool>(n+1, false);
    dfs(1);
    
    for(int i = 1; i<= n; i++)
    {
        if(dist[i] != dist_2[i])
        {
           if(v_dfs[i])
            {
                v_dfs = vector<bool>(n+1, false);
                dfs(i);
                if(v_dfs[n])
                {
                    cout<<-1;
                    return 0;
                }
            }
        }
    }
   
    cout<<dist[n];
 
    return 0;
}
