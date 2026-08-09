//
//  main.cpp
//  72. Edit Distance
//
//  Created by Yousef on 12.06.26.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int length_1  = word1.size(), length_2 = word2.size();
        
        if(length_1 == 0)
            return length_2;
        if(length_2 == 0)
            return length_1;
        
        vector<vector<int>>dp (length_1 + 1, vector<int>(length_2 + 1, 0));
        
        int cost;
        
        for(int i = 0; i <= length_1; i++)
            for(int j = 0; j <= length_2; j++)
            {
                if(i == 0)
                {
                    dp[0][j] = j;
                    continue;
                }
                if(j == 0)
                {
                    dp[i][0] = i;
                    continue;
                }
                cost = 1;
                if(word1[i - 1] == word2[j - 1])
                    cost = 0;
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                dp[i][j] = min (dp[i][j], dp[i-1][j-1] + cost);
                
            }
        
        return dp[length_1][length_2];
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    cout<<s.minDistance("ros", "ros");
    return 0;
}
