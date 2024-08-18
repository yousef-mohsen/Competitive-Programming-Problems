//
//  main.cpp
//  Distinct Colors
//
//  10.01.21.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;
vector<ll> c, ans;
vector<vector<ll>> adj;
vector<set<ll>> s;

void dfs(ll u, ll p)
{
    for(auto v: adj[u])
    {
        if(v != p)
        {
            dfs(v, u);
            //if(s[v].size() > s[u].size())
              //  swap(s[v], s[u]);
            
            for(auto t: s[v])
                s[u].insert(t);
        }
        
    }
    ans[u] = s[u].size();
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, a, b;
    cin>>n;
    c.resize(n + 1);
    ans.resize(n + 1);
    adj.resize(n + 1, vector<ll>());
    s.resize(n + 1, set<ll>());
    
    for(int i = 1; i <= n; i++)
    {
        cin>>c[i];
        s[i].insert(c[i]);
    }
    for(int i = 1; i < n; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        cout<<ans[i]<<" ";
    return 0;
}
