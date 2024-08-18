//
//  main.cpp
//  B1. EKG
//
//  Created by Yousef on 13.08.20.
//

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

vector<vector<int>> adj;
vector<bool> p;
vector <long long > dist;
vector<int> id;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x, a;
    cin>>n>>x;
    adj = vector<vector<int>> (n + 1);
    p = vector<bool> (n + 1, false);
    dist = vector<long long> (n + 1, 0);
    id = vector<int> (n+1, 0);
    
    for(int i = 1; i<=n; i++)
    {
        cin>>a;
        
        if(a!=0)
        {
            adj[a].push_back(i);
            p[i] = true;
        }
}
    int ids = 0;
    for(int i =1; i<=n; i++)
    {
        if(!p[i])
        {
            ids++;
            dist[i]=1;
            int t =i;
            auto u = adj[i];
            while(u.size() != 0)
            {
                id[t] =ids;
                dist[adj[t][0]] = dist[t] + 1;
                u = adj[adj[t][0]];
                t = adj[t][0];
            }
            id[t] = ids;
        }
    }
    
    bitset<1005> b;
   
    for(int i = 1; i<=n ; i++)
    {
        if(adj[i].size() ==0 && id[i] !=id[x])
        {
            bitset<1005> temp;
            b |= b << (dist[i]);
            temp[dist[i]] = 1;
            b|= temp;
        }
    }
    

    b = b<<dist[x];
    b[dist[x]] = 1;
    
    for(int i =1; i<=n; i++)
    {
        if(b[i] == 1)
        {
            cout<<i<<"\n";
            
        }
    }
    
  
    return 0;
}
