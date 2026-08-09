//
//  main.cpp
//  139. Word Break
//
//  Created by Yousef on 19.06.26.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int size = wordDict.size(), counter = 0;
        int length = s.length();
        
        vector<vector<int>> t(size * 20 + 5, vector<int> (26, -1));
        vector<bool> end (size * 20 + 5, false);
        vector<bool> dp (length, false);
        
        
        for(int i = 0; i < size; i++)
        {
            int word_size = wordDict[i].size(), n = 0;
            for(int k = 0; k < word_size; k++)
            {
                if(t[n][wordDict[i][k] - 'a'] == -1)
                {
                    t[n][wordDict[i][k] - 'a'] = ++counter;
                    n = counter;
                }
                else
                {
                    n = t[n][wordDict[i][k] - 'a'];
                    if(k == word_size - 1)
                        end[n] = true;
                    
                }
            }
            end[counter] = true;
        }
        
        for(int i = 0; i < length; i++)
        {
            int start = i, n = t[0][s[start] - 'a'];
            
            if(i > 0 && dp[i - 1] == false)
                continue;
            while(start < length && n != -1)
            {
                if(end[n])
                {
                    dp[start] = true;
                    //dp[i] = true;
                }
                start ++;
                if(start < length)
                    n = t[n][s[start] - 'a'];
                
            }
            
        }
        return dp[length - 1];
        
        
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> t = {"car", "ca", "rs"};
    cout<<s.wordBreak("cars", t);
    return 0;
}
