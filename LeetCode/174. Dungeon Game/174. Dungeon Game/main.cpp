//
//  main.cpp
//  174. Dungeon Game
//
//  Created by Yousef on 27.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        
        vector<vector<int>> dp = vector<vector<int>> (n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0)
                    dp[i][j] = dungeon[0][0];
                if(i == 0 && j > 0)
                    dp[i][j] = min(dp[i][j - 1], dungeon[i][j]);
                if(i > 0 && j == 0)
                    dp[i][j] = min(dp[i - 1][j], dungeon[i][j]);
                
                if(i > 0 && j > 0)
                {
                    dp[i][j] = min(dungeon[i][j] ,max(dp[i-1][j], dp[i][j - 1] ));
                }
            }
        /*
        int i = n - 1, j = m - 1;
        int mn = dp[n - 1][m - 1];
        while(!(i == 0 && j == 0))
        {
            mn = min(mn, dp[i][j]);
            if(j == 0)
            {
                i--;
                continue;
            }
            if(i == 0)
            {
                
                j--;
                continue;
            }
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;
            
        }
        mn = min(mn, dp[0][0]);
        */
        
        if(dp[n - 1][m - 1] <= 0)
            return -1* dp[n - 1][m - 1] + 1;
        return 0;
    }
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> test = {
        {-2,-3,3},{-5,-10,1},{10,30,-5}
        
    };
    s.calculateMinimumHP(test);
    return 0;
}
