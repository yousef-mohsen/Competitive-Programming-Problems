//
//  main.cpp
//  91. Decode Ways
//
//  Created by Yousef on 22.06.26.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        
        if(s[0] == '0')
            return 0;
        vector<int> dp(size, 0);
        vector<int> dp2(size, 0);
        dp[0] = 1;
        dp2[0] = 0;
        
        for(int i = 1; i < size; i++)
        {
            if(
               (s[i] == '0' && s[i - 1] - '0' > 2) ||
               (s[i] == '0' && s[i - 1] == '0')
               )
                return 0;
            
            if(s[i - 1] == '0')
            {
                dp[i] = dp[i - 1];
                dp2[i] = 0;
                continue;
            }
            if(s[i] == '0')
            {
                if(i == 1)
                    dp[i] = dp[i - 1];
                else
                    dp[i] = dp[i - 1] - 1;
                dp[2] = 0;
                continue;
            }
            
            if(stoi(s.substr(i - 1,2)) <= 26)
            {
                dp[i] = dp[i - 1] + dp2[i - 1];
                dp2[i] = dp[i - 1];
            }
            else
            {
                dp[i] = dp[i - 1];
                dp2[i] = 0;
            }
            
        }
        
        
        return dp[size - 1];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.numDecodings("1123");
    return 0;
}
