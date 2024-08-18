//
//  main.cpp
//  Counting Paths
//
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> adj;
vector<ll>e;
vector<vector<ll>> p;
vector<ll> in;
vector<ll> out;
vector<ll> l;
vector<ll> ans;
ll t = 0;

bool test (ll a, ll b)
{
    return(in[a] < in [b] && out[a] > out [b]);
}

ll lca (ll a, ll b)
{
    if(test (a, b))
        return a;
    if(test(b,a))
        return b;
    ll u = a;
    for(int i = 17; i >= 0; i--)
    {
        if(p[i][u] != 0 && !(test(p[i][u],b)))
            u = p[i][u];
    }
    return p[0][u];
}

void dfs(ll u, ll pa)
{
    t++;
    in[u] = t;
    p[0][u] = pa;
    for(auto v: adj[u])
        if(v != pa)
            dfs(v, u);
    t++;
    out[u] = t;
}

void dfs2(ll u, ll pa){
    
    for(auto v: adj[u])
        if(v != pa)
        {
            dfs2 (v, u);
            l[u] += l[v];
        }
    
    };

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, q, a, b;
    cin>>n>>q;
    adj = vector<vector<ll>> (n + 1);
    e = vector<ll> (n + 1);
    p = vector<vector<ll>> (18, vector<ll>(n + 1));
    in = vector<ll> (n + 1);
    out = vector<ll> (n + 1);
    l = vector<ll> (n + 1, 0);
    ans = vector<ll> (n + 1, 0);
    
    for(int i = 1; i < n ; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    
    for(int i = 1; i < 18; i ++)
        for(int k = 1; k <= n; k++)
        {
            p[i][k] = p[i - 1][p[i - 1][k]];
        }
    ll temp;
    while(q--)
    {
        cin>>a>>b;
        if(a == b)
        {
            l[a]++;
            l[p[0][a]] --;
        }else
        {
            temp = lca(a,b);
            l[a]++;
            l[b]++;
            l[temp]--;
            l[p[0][temp]] --;
        }
    }
    dfs2(1, 0);
    for(int i = 1; i <= n; i++)
        cout<<l[i]<<" ";
    return 0;
}
