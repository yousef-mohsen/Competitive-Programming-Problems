//
//  main.cpp
//  Subtree Queries
//
//  Created by Yousef on 01.01.21.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <stack>

using namespace std;
typedef long long ll;
vector<ll> v;
vector<ll> values;
vector<vector<ll>> adj;
vector<ll> sub;
vector<bool> visited;
ll si;
vector<ll> s;
ll counter = 1;

void add(ll a, ll b)
{
    a += si - 1;
    v[a] = b;
    for(a /=2; a >= 1; a/=2)
    {
        v[a] = v[2 * a] + v[2 * a + 1];
    }
}
void dfs(ll u)
{
    add(counter, values[u]);
    s[u] = counter;
    counter++;
    visited[u] = true;
    sub[u] = 1;
    
    for(auto v: adj[u])
    {
        if(!visited[v])
        {
            dfs(v);
            sub[u] += sub[v];
        }
    }
}
ll sum (ll a, ll b, ll k, ll x, ll y)
{
    if(b < x || a > y)
        return 0;
    if(a <= x && y <= b)
        return v[k];
    ll d = (x + y)/2;
    
    return sum (a, b, 2 * k, x, d) + sum (a, b, 2 * k + 1, d + 1, y);
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n , q, a, b, t;
    cin>>n>>q;
    si = 1<<int(ceil(log2(n)));
    v = vector<ll>(2 * si, 0);
    values = vector<ll> (n + 1);
    adj= vector<vector<ll>> (n + 1);
    sub = vector<ll> (n + 1);
    visited = vector<bool> (n + 1, false);
    s = vector<ll> (n + 1);
    
    for(int i = 1; i <= n; i++)
        cin>>values[i];
    
    for(int i = 1; i < n; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);
    while(q--)
    {
        cin>>t;
        if(t == 1)
        {
            cin>>a>>b;
            add(s[a], b);
        }
        else
        {
            cin>>a;
            cout<<sum(s[a]  ,s[a] + sub[a] - 1, 1, 1, si)<<"\n";
        }
    }

    return 0;
}
