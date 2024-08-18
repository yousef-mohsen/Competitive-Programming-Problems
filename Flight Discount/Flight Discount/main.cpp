//
//  main.cpp
//  Flight Discount
//
//  12.09.20.
//

#include <iostream>
#include <vector>
#include <utility>
#include <queue>


using namespace std;
typedef long long ll;

void dij (vector<vector<pair<ll,ll>>> &adj, vector<ll>& dist, ll b, vector<bool> p)
{
    priority_queue<pair<ll, ll>> q;
    q.push({0, b});
    while(!q.empty())
    {
        auto i = q.top();
        q.pop();
        if(p[i.second])
            continue;
        for(auto z: adj[i.second])
        {
            ll temp = dist[i.second] + z.second;
            if(temp < dist[z.first])
            {
                q.push({-temp, z.first});
                dist[z.first] = temp;
            }
        }
        p[i.second] = true;
    }
}



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n, m, a, b, c;
    ll inf = 1e15;
    cin>>n>>m;
    vector <vector<pair <ll, ll>>> adj(n + 1);
    vector <vector<pair <ll, ll>>> adj2(n + 1);
    vector<ll> dist(n + 1, inf);
    vector<ll> dist2(n + 1, inf);
    
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b, c));
        adj2[b].push_back(make_pair(a, c));

    }
    
    dist[1] = 0;
    dist2[n] = 0;
    vector <bool> p (n + 1, false);
    dij(adj, dist, 1, p);
    p = vector<bool>(n + 1, false);
    dij(adj2, dist2, n, p);
    
    ll ans = inf;
    
    for(int i = 1; i <= n; i++)
    {
        for(auto t: adj [i])
        {
            ans = min (ans, dist[i] + t.second/2 + dist2[t.first]);
        }
    }
    
    cout<<ans;
    return 0;
}
