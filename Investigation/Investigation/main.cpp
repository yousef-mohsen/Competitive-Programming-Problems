//
//  main.cpp
//  Investigation
//
//  Created by Yousef on 13.09.20.
//

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n, m, a, b, c, mo = 1e9 + 7;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj (n + 1);
    vector<ll> mi (n + 1, 1e17);
    vector<ll> ma (n + 1, -1e17);
    vector<ll> dist (n + 1, 1e17);
    vector<ll> p (n + 1,0);
    vector<bool> v (n + 1, false);
    for(int i = 1; i <= m; i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    
    priority_queue < pair<ll,ll>, vector<pair<ll,ll>>, greater <pair<ll,ll>>> q;
    q.push({0, 1});
    dist[1] = 0;
    mi[1] = 0;
    ma[1] = 0;
    p[1] = 1;
    
    while(!q.empty())
    {
        auto i = q.top();
        q.pop();
        
        if(!v[i.second])
        for (auto t: adj[i.second])
        {
            ll temp = dist[i.second] + t.second;
            if(temp < dist[t.first])
            {
                dist[t.first] = temp;
                q.push({temp, t.first});
                mi[t.first] = mi[i.second] + 1;
                ma[t.first] = ma[i.second] + 1;
                p[t.first]= p[i.second];
                if(p[t.first] > mo)
                    p[t.first]-=mo;
                
            }
            else if (temp == dist[t.first])
            {
                mi[t.first] = min (mi[t.first], mi[i.second] + 1);
                ma[t.first] = max (ma[t.first], ma[i.second] + 1);
                p[t.first] += p[i.second];
                if(p[t.first] > mo)
                    p[t.first]-=mo;
            }
            
        }
        v[i.second] = 1;
        
    }
    cout<<dist[n]<<" "<<p[n]%mo<<" "<<mi[n]<<" "<<ma[n];
    
    return 0;
}

