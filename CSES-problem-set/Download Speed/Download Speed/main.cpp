//
//  main.cpp
//  Download Speed
//
//  Created by Yousef on 25.12.20.
//
 
#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
 
using namespace std;
typedef long long  ll;
ll flow , n, cri;
vector<ll> capacity;
vector<vector<ll>> adj;
vector<ll> edge;
vector<bool> visited;
bool e = false;
void dfs(ll u, ll value, ll bottle)
{
    
    for (auto a: adj[u])
    {
        if(!visited[edge[a]])
        if(capacity[a] >= value)
        {
            visited[edge[a]] = true;
            if(edge[a] == n)
            {
                cri = min(bottle, capacity[a]);
                e = true;
                flow += cri;
            }
            else
            {
                dfs(edge[a], value, min(bottle, capacity[a]));
                //visited[edge[a]] = false;
            }
            if(e)
            {
                capacity[a]-= cri;
                if(a&1)
                    capacity[a + 1] += cri;
                else
                    capacity[a-1] += cri;
                
                return;
            }
        }
       
    }
}
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll m, a, b, c, ma = -1;
 
    cin>>n>>m;
    capacity = vector<ll>(2 * m + 1);
    adj = vector<vector<ll>> (n + 1, vector<ll>());
    edge = vector<ll> (2 * m + 1);
    
    int counter = 1;
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        ma = max(ma, c);
        edge[counter] = b;
        edge[counter + 1] = a;
        capacity[counter] = c;
        capacity[counter + 1] = 0;
        adj[a].push_back(counter);
        adj[b].push_back(counter + 1);
        counter += 2;
    }
    ma = log2(ma);
    ma = 1<<ma;
    while(ma>=1)
    {
        ll temp;
        do
        {   temp = flow;
            visited = vector<bool> (n + 1, false);
            e = false;
            dfs(1, ma, 1e17);
        }while(temp != flow);
        ma/=2;
    }
    cout<<flow;
    return 0;
}
