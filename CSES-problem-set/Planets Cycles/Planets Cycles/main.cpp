//
//  main.cpp
//  Planets Cycles
//
//  Created by Yousef on 29.12.20.
//

#include <iostream>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;
typedef long long ll;

vector<vector<ll>> d;
vector<bool> visited;
vector<vector<ll>> adj;
vector<vector<ll>> adj2;
vector<ll> comp;
vector<ll> order;
//map<ll,ll> m;
vector<ll> m ;
stack <ll> s;

void dfs(ll u, ll &o)
{
    visited[u] = true;
    o++;
    order[u] = o;
    for(auto v: adj[u])
    {
        if(!visited[v])
        {
            dfs(v, o);
        }
        s.push(u);
    }
    
}
void dfs2(ll u , ll counter)
{
    visited[u] = true;
    comp[u] = counter;
    m[counter] += 1;
    for(auto v: adj2[u])
    {
        if(!visited[v])
        {
            dfs2(v, counter);
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, q, x, a, b;
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    vector<ll> v(n + 1);
    visited = vector<bool> (n + 1, false);
    d = vector<vector<ll>> (19, vector<ll> (n + 1));
    comp = vector<ll> (n + 1, 0);
    order = vector<ll> (n + 1);
    adj = vector<vector<ll>> (n + 1);
    adj2 = vector<vector<ll>> (n + 1);
    m = vector<ll> (n + 1, 0);
    for(int i = 1; i <=n; i++)
    {
        cin>>v[i];
        d[0][i] = v[i];
        adj[i].push_back(v[i]);
        adj2[v[i]].push_back(i);
        
    }
    
    for(int i = 1; i <= 17; i++)
    {
        for(int z = 1; z <= n; z++)
        {
            d[i][z] = d[i - 1][d[i - 1][z]];
        }
    }
    
    ll o = 0;
    for(int i = n; i >= 1; i--)
    {
        if(!visited[i])
            dfs(i, o);
    }
    visited = vector<bool> (n + 1, false);
    ll counter = 0;
    
    int temp = 0;
    
    while (s.size() > 0)
    {
        temp = s.top();
        s.pop();
        if(comp[temp] == 0)
        {
            counter ++;
            m[counter] = 0;
            dfs2(temp, counter);
        }
    }
  
    for (int i = 1; i <= n; i++)
    {
        if(adj[i][0] == i)
        {
            cout<<1<<" ";
        }
        else if (m[comp[i]] > 1)
            cout<<m[comp[i]]<<" ";
        else
        {
            ll u = i , k = i, value = 0;
            for(int z = 17; z >= 0; z--)
            {
                k = d[z][u];
                if(m[comp[k]] == 1 && adj[k][0] != k)
                {
                    value += (1<<z);
                    u = k;
                }
            }
            u = d[0][u];
            value++;
            cout<<value + m[comp[u]]<<" ";
            }
        }
    
    return 0;
}

