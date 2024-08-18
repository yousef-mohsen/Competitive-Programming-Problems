//
//  main.cpp
//  Flight Routes
//
//  Created by Yousef on 13.09.20.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m, k, a, b, c;
    cin>>n>>m>>k;
    vector<vector<pair<ll,ll>>> adj(n + 1);
    vector<long long> ans;
    vector<long long > count (n + 1, 0);
    for(int i = 1; i <= m; i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    
    
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    
    q.push({0, 1});
    while(!q.empty() && ans.size() < k)
    {
        auto i = q.top();
        count[i.second]++;
        q.pop();
        if(i.second == n)
            ans.push_back(i.first);
        
        if(count[i.second]<=k)
        for(auto e: adj[i.second])
            q.push({i.first + e.second, e.first});
    }
    
    
    for(int i = 0; i < k; i++)
    {
        cout<<ans[i]<<" ";
    }
    
    
    
    
    
    
    return 0;
}
