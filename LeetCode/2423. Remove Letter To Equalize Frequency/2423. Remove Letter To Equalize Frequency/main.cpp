//
//  main.cpp
//  2423. Remove Letter To Equalize Frequency
//
//  Created by Yousef on 27.05.26.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool equalFrequency(string word) {
        
        vector <int> v ('z'- 'a' + 1, 0);
        vector <int> ans;
        int id;
        
        for(auto l: word)
        {
            v[l-'a']++;
        }
        for(int i = 0; i < v.size(); i ++)
            if(v[i] != 0)
                ans.push_back(v[i]);
        
        sort(ans.begin(), ans.end());
        int last = ans.size() - 1;
        if(ans[0]  == 1)
        {
            if (ans[1] == ans[last])
                    return true;
        }
        
        ans[last] --;
        return ans[0] == ans[last];
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    cout<<s.equalFrequency("bac");
    return EXIT_SUCCESS;
}
