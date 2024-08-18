//
//  main.cpp
//  Distance Queries
//
//

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adj;
vector<int> tin;
vector<int> tout;
vector<int> dis;
vector<vector<int>> d;

int counter = 0, tt = 0;

void dfs(int u, int p)
{
    counter++;
    tin[u] = counter;
    for(auto v: adj[u])
        if(v!= p)
        {
            d[0][v] = u;
            dis[v] = dis[u] + 1;
            dfs(v, u);
        }
    counter++;
    tout[u] = counter;
}
bool anc (int u , int v)
{
    return (tin[u] < tin[v])&& (tout[u] > tout[v]);
}
int lca(int u, int v)
{
    if(anc(u, v))
        return u;
    if(anc(v, u))
        return v;
    for(int i = tt; i >= 0; i--)
    {
        int k = d[i][u];
        if(k!= 0 && !anc(k, v))
            u = k;
    }
    return d[0][u];
    
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, a, b, t, temp, c = 1;
    cin>>n>>q;
    adj = vector<vector<int>> (n + 1, vector<int>());
    tin = vector<int> (n + 1);
    tout = vector<int> (n + 1);
    dis = vector<int> (n + 1);
    t = n;
    
    while(t)
    {
        if(t & 1)
            tt = c;
        c++;
        t = t>>1;
    }
    
    d = vector<vector<int>>(tt + 1, vector<int>(n + 1));
    d[1][1] = 0;
    
    cout<<tt;
    for(int i = 1; i < n; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        
    }
    dis[1] = 1;
    dfs(1,0);
    
    for(int i = 1; i <= tt; i++)
    {
        for(int k = 1; k <=n; k++)
            d[i][k] = d[i - 1][d[i - 1][k]];
    }
    
    for(int i = 1; i <= q; i++)
    {
        cin>>a>>b;
        if(a==b)
        {
            cout<<0<<"\n";
        }
        else
        {
            temp = lca(a,b);
            cout<<dis[a] - 2 * dis[temp] + dis[b]<<"\n";
        }
    }
    
    
    
    return 0;
}
