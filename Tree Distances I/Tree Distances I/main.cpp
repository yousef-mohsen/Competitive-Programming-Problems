//
//  main.cpp
//  Tree Distances I
//
//  Created by Yousef on 23.09.20.
//

#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

vector<bool> visited;
vector<vector<int>> adj;
vector<set<pair<int, int>>> dis;
vector<int> parent;
vector<int> order;
int counter = 0;

void dfs(int n)
{
    visited[n] = true;
    for(auto a: adj[n])
    {
        if(!visited[a])
        {
            parent[a] = n;
            order[counter] = a;
            counter++;
            dfs(a);
       
            if(dis[n].size() < 2)
            {
                auto t = dis[a].rbegin();
                dis[n].insert(make_pair((*t).first + 1, a));
            }
            else
            {
                auto t = dis[a].rbegin();
                auto temp = dis[n].begin();
                if((*t).first + 1 > (*temp).first)
                {
                    dis[n].erase(temp);
                    dis[n].insert(make_pair((*t).first + 1, a));
                    
                }
                
            }
        }
    }
}


int main(int argc, const char * argv[]) {
   ios::sync_with_stdio(0); cin.tie(0);
    int n, a, b;
    cin>>n;
    adj = vector<vector<int>>(n + 1, vector<int>());
    visited = vector<bool> (n + 1, false);
    dis = vector<set<pair<int, int>>> (n + 1);
    parent = vector<int> (n + 1);
    order = vector<int> (n);

    
    for(int i = 1; i <= n; i++)
    {
        dis[i].insert({0, i});
    }
    for(int i = 1; i < n; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited[1] = true;
    
    dfs(1);
    
    for(auto a: order)
    {
        auto t = (dis[parent[a]]).rbegin();
        auto p = dis[parent[a]].size();
        auto t2 = dis[a].begin();
        while(p--)
        {
            if((*t).second == a)
            {
                t++;
                continue;
            }
            if((*t).first + 1 > (*t2).first )
            {
                dis[a].erase({(*t2).first, (*t2).second});
                dis[a].insert({(*t).first + 1, parent[a]});
                break;
            }
        }
         
    }
   
    for(int i = 1; i <=n; i++)
    {
        auto t = dis[i].rbegin();
        cout<<(*t).first<<" ";
    }
      
    return 0;
}
