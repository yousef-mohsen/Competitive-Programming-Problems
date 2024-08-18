//
//  main.cpp
//  Police Chase
//
//  Created by Yousef on 25.12.20.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <set>
using namespace std;

typedef long long ll;
vector<ll> capaity;
vector<vector<ll>> adj;
vector<tuple<ll,ll,ll>> edge;
vector<bool> visited;
ll flow = 0, n;
bool e = false;
vector<bool> taken;

void dfs(ll u)
{
    for (auto v: adj[u])
        if(get<2>(edge[v]) == 1 && !visited[get<1>(edge[v])])
        {
            visited[get<1>(edge[v])] = true;
            if(get<1>(edge[v]) == n)
            {
                e = true;
                flow += 1;
            }
            else
            {
                dfs(get<1>(edge[v]));
            }
            if(e)
            {
                get<2>(edge[v]) --;
                
                if(v&1)
                    get<2>(edge[v + 1]) ++;
                else
                    get<2>(edge[v - 1]) ++;
                    
                return;
            }
        }
}

void dfs2(ll u)
{
    if(!taken[u])
        taken[u] = 1;
    for (auto v: adj[u])
        if(get<2>(edge[v]) == 1 && !taken[get<1>(edge[v])])
            dfs2(get<1>(edge[v]));
    
}

int main(int argc, const char * argv[]) {
    ll  m, a, b;
    cin>>n>>m;
    capaity = vector<ll> (4 * m + 1);
    edge = vector<tuple<ll,ll,ll>> (4 * m + 1);
    adj = vector<vector<ll>> (n + 1, vector<ll>());
    taken = vector<bool>(n + 1, false);
    set<pair<ll, ll>> ans;
    int counter = 1;
    
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;
        adj[a].push_back(counter);
        edge[counter] = {a,b,1};
        
        adj[b].push_back(counter + 1);
        edge[counter + 1] = {b,a,0};
               
        adj[b].push_back(counter + 2);
        edge[counter + 2] = {b,a, 1};
        
        adj[a].push_back(counter + 3);
        edge[counter + 3] = {a,b, 0};
        counter += 4;
        
    }
    
    ll temp;
    do
    {   temp = flow;
        visited = vector<bool> (n + 1, false);
        e = false;
        dfs(1);
    }while(temp != flow);
    
    cout<<flow<<"\n";
    dfs2(1);
    
    for (int i = 1; i <= n; i++)
    {
        if(taken[i])
            for(auto v: adj[i])
                if(!taken[get<1>(edge[v])])
                {
                    int t = get<1>(edge[v]);
                    ans.insert({min(i,t), max(i,t) }) ;
                }
    }
    
    for(auto t: ans)
    {
        cout<<t.first<<" "<<t.second<<"\n";
    }
    
    return 0;
}
