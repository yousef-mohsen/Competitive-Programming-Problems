//
//  main.cpp
//  Shortest Routes I
//
//  Created by Yousef on 12.03.20.
//  Copyright © 2020 Yousef. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    long long c;
    long long inf = 1e18;
    priority_queue< pair<long long , int> > q;
    
    cin>>n>>m;
    
    vector <pair<int, long long >> * adj = new vector <pair<int, long long >>[n + 1];
    vector<long long > dist (n + 1, inf);
    vector<bool> visited (n + 1, false);
    
    for(int i = 1; i <= m; i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    
    dist [1] = 0;
    q.push({0,1});
    
    while(!q.empty())
    {
        int a = q.top().second; // rkm l node
        q.pop();
        if(visited[a])
            continue;
        visited[a] = true;
        for(auto n: adj[a])//{byro7 feen, weight}
        {
            if(dist[n.first] > dist[a] + n.second)
            {
                dist[n.first] = dist[a] + n.second;
            }
            
            q.push({-1 * dist[n.first], n.first});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout<<dist[i]<<" ";
    }
    
    return 0;
}
