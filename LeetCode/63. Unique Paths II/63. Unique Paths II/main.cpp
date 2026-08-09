//
//  main.cpp
//  63. Unique Paths II
//
//  Created by Yousef on 12.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0])
            return 0;
        
        vector<vector<int>> dp (m, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++)
            for(int k = 0; k < n; k++)
            {
                if(obstacleGrid[i][k])
                    continue;
                
                if(i == 0 && k > 0)
                {
                    dp[i][k] = dp[i][k - 1];
                    continue;
                    
                }
                if(k == 0 && i > 1)
                {
                    dp[i][k] = dp[i - 1][k];
                    continue;
                }
                
                if(i > 0)
                    dp[i][k] += dp[i - 1][k];
                if(k > 0)
                    dp[i][k] += dp[i][k - 1];
                    
            }
        return dp[m - 1][ n - 1];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
