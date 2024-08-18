//
//  main.cpp
//  Hamiltonian Flights
//
//  Created by Yousef on 22.12.20.
//
 
#include <iostream>
#include <set>
#include <vector>
typedef long long ll;
using namespace std;
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b;
    cin>>n>>m;
    ll l = (1<<n), mo = 1e9 + 7;
    
    
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b;
        adj[a][b] += 1;
    }
    vector<vector<ll>> dp(l, vector<ll>(n,0));
    dp[1<<(n-1)][0] = 1;
    int i =1<<(n-1);
    i++;
    for(; i < l; i++)
    {
        for(int k = 0; k < n; k++)
        {
            if(i & (1<<k))
            {
                for(int q = 0; q < n; q++)
                       {
                           if(!dp[i^(1<<k)][q])
                               continue;
                           if(adj[q + 1][n - k])
                           {
                               dp[i][n - k - 1] += dp[i^(1<<k)][q]
                               *adj[q + 1][n - k]  ;
                               if (dp[i][n - k - 1] > mo)
                                   dp[i][n - k - 1]%= mo;
                           }
                       }
                 }
        }
    }
 
    cout<<dp[l-1][n-1];
    
    return 0;
}
