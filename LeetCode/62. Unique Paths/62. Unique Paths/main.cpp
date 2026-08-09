//
//  main.cpp
//  62. Unique Paths
//
//  Created by Yousef on 12.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp (m, vector<int> (n, 0));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++)
            for(int k = 0; k < n; k++)
            {
                if(i > 0)
                    dp[i][k] += dp[i - 1][k];
                if(k > 0)
                    dp[i][k] += dp[i][k - 1];
            }
        return dp[m - 1][n - 1];
    }
};

int main(int argc, const char * argv[]) {
      return 0;
}
