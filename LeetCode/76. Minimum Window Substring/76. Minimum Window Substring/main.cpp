//
//  main.cpp
//  76. Minimum Window Substring
//
//  Created by Yousef on 23.06.26.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<vector<int>> s_n ('z' - 'A' + 1, vector<int>());
        vector<int> t_n ('z' - 'A' + 1, 0);
        
        int size_s = s.size(), size_t = t.size();
        for (int i = 0; i < size_s; i++)
        {
            s_n[s[i] - 'A'].push_back(i);
        }
        
        for (int i = 0; i < size_t; i++)
        {
            t_n[t[i] - 'A'] ++;
        }
        
        int l = s_n.size();
        for(int i = 0; i < l; i++)
        {
            if(t_n[i] > s_n[i].size())
                return "";
        }
        
        
        int s_f = 0, e_f = size_s - 1, m = size_s;
        for(int i = 0; i < size_s; i ++)
        {
            int end = size_s;
            bool found = true;
            for(int k = 0; k < l; k++)
            {
                if(!t_n[k])
                    continue;
                auto it = lower_bound(s_n[k].begin(), s_n[k].end(), i);
                if(it == s_n[k].end() || s_n[k].end() - it < t_n[k])
                {
                    return s.substr(s_f, e_f - s_f + 1);
                }
                if(end == size_s)
                    end = *(t_n[k] + it  - 1);
                else
                    end = max(end, *(t_n[k] + it  - 1));
                
            }
                if(end - i < m)
                {
                    s_f = i;
                    e_f = end;
                    m = end - i;
                }
            
            
        }
        return s.substr(s_f, e_f - s_f + 1);
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.minWindow("cabwefgewcwaefgcf", "cae");
    return EXIT_SUCCESS;
}
