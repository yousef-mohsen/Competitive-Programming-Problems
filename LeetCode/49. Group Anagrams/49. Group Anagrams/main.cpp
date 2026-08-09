//
//  main.cpp
//  49. Group Anagrams
//
//  Created by Yousef on 19.06.26.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int size = strs.size();
        vector<vector<int>> v(size, vector<int> (28, 0));
        //vector<bool> taken(size, false);
        //int counter = 0;
        
        for(int i = 0; i < size; i++)
        {
            int length = strs[i].size();
            
            for(int k = 0; k < length; k++)
            {
             
                v[i][strs[i][k] - 'a'] ++;
            }
            v[i][26] = i;
        }
        
        sort(v.begin(), v.end());
        int group = 0;
        
        for (int i = 0; i < size - 1; i ++)
        {
            if(equal(v[i].begin(), v[i].begin() + 26, v[i + 1].begin()))
            {
                v[i][27] = group;
                v[i + 1][27] = group;
            }
            else
            {
                v[i][27] = group;
                group ++;
                v[i + 1][27] = group;
            }
        }
        
        vector<vector<string>> ans(group + 1, vector<string>());
        
        for(int i = 0; i <size; i++)
        {
            ans[v[i][27]].push_back(strs[v[i][26]]);
        }
        
        return ans;
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<string> test = {"eat","tea","tan","ate","nat","bat"};
    
    s.groupAnagrams(test);
    
    
    return 0;
}
