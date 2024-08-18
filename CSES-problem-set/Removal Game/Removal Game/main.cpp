//
//  main.cpp
//  Removal Game
//
//  Created by Yousef on 06.09.20.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    
    vector<long long> v (n + 1);
    vector<long long> sum (n + 1);
    sum[0] = 0;
    vector <vector<long long>> dp(n+1, vector<long long>(n + 1));
    
    for(int i = 1; i <= n; i++)
    {
        cin>>v[i];
        sum[i] = v[i] + sum[i - 1];
        dp[i][i] = v[i];
    }
    
 
    int counter = 1;
    int t = n;
    while(counter <= n)
    {
        for(int i = 1; i < t; i++)
        {
            long long s = sum[i + counter] - sum[i - 1];
            dp[i][i + counter] = max(s - dp[i][i + counter - 1], s - dp[i + 1][i + counter]);
        }
        t--;
        counter ++;
    }
    
    cout<<dp[1][n];
    
    
    return 0;
}
