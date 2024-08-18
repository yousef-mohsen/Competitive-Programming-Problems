//#include <bits/stdc++.h>
#define sz(c)       int(c.size())
#define rep(i,a,b)  for (int i=a; i<(b); ++i)
#define per(i,a,b)  for (int i=(b)-1; i>=(a); --i)
#define fore(c,...) for (auto __VA_ARGS__:(c))

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
 
 
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //cout<<fixed<<setprecision(10);
 
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    rep(i,0,m) {
        int a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].emplace_back(b,i);
        adj[b].emplace_back(a,i);
    }
 
    rep(i,0,n) if (sz(adj[i])%2!=0) {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
 
    vector<int> pt(n);
    vector<bool> used(m);
    vector<int> res;
    function<void(int)> euler=[&](int v) {
        for (int &i=pt[v]; i<sz(adj[v]);) {
            auto [u,e]=adj[v][i++];
            if (!used[e]) {
                used[e]=true;
                euler(u);
            }
        }
        res.emplace_back(v);
    };
 
    euler(0);
 
    if (sz(res)<=m) {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
 
    fore(res,i) cout<<i+1<<" ";
    cout<<'\n';
}
