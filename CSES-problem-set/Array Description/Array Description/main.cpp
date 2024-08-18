//
//  main.cpp
//  Array Description
//
//  Created by Yousef on 06.09.20.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a;
    long long mo = 1e9 + 7;
    cin>>n>>m;
    vector<long long> v(n + 1);
    
    for(int i = 1; i<= n; i++)
    {
        cin>>a;
        v[i] = a;
    }
    vector <vector<long long >> dp (n + 2, vector<long long>(m + 2, 0));
    
    if(v[1] != 0)
        dp[1][v[1]] = 1;
    else
    {
        for(int i = 1; i<= m; i++)
        {
            dp[1][i] = 1;
        }
    }
    
    for(int i = 2; i <= n; i++)
    {
        if(v[i])
        {
            dp[i][v[i]] =dp[i - 1][v[i] - 1] +dp[i - 1][v[i]] + dp[i - 1][v[i] + 1];

            if(dp[i][v[i]] >= mo)
                dp[i][v[i]] %= mo;
            
            continue;
        }
        for(int k = 1; k <= m; k++)
        {
            dp[i][k] =dp[i - 1][k - 1] +dp[i - 1][k] + dp[i - 1][k + 1];

            if(dp[i][k] >= mo)
                dp[i][k] %= mo;
            
        }
    }
    
    long long ans = 0;
    
    for(int i = 1; i <= m; i++)
    {
        ans+= dp[n][i];
        if(ans >= mo)
            ans %= mo;
    }
    
    cout << ans;
    
    
    return 0;
}
