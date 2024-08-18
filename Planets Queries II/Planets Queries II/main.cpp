//
//  main.cpp
//  Planets Queries II
//
//  Created by Yousef on 29.12.20.
//

#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;

vector<vector<ll>> d;
vector<bool> visited;
vector<vector<ll>> adj;
vector<vector<ll>> adj2;
vector<ll> comp;
vector<ll> order;
//map<ll,ll> m;
stack <ll> s;
vector<ll> m;
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
    cin>>n>>q;
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
    for(int i = 1; i <=n; i++)
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
  
    while(q--)
    {
        cin>>a>>b;
        if(a == b)
        {
            cout<<0<<"\n";
        }
        else if (comp[b] < comp[a])
            cout<<-1<<"\n";
       
        else
        {
            ll u = a , k = a, value = 0;
            for(int i = 17; i >= 0; i--)
            {
             
                k = d[i][u];
                if(comp[k] < comp[b])
                {
                    value += (1<<i);
                    u = k;
                }
            }
            u = d[0][u];
            if(u == b)
            {
                cout<<value + 1<<"\n";
            }
            else if (comp[u] == comp[b])
            {
                if(order[u] < order [b])
                    {
                        cout<<order[b]-order[u] + value + 1<<"\n";
                    }
                    else
                    {
                        cout<<m[comp[u]] + order[b] - order [u] + value + 1<<"\n";
                    }
                }
            else
            {
                cout<<-1<<"\n";
            }
        }
    }
    
    return 0;
}

