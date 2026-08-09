//
//  main.cpp
//  567. Permutation in String
//
//  Created by Yousef on 13.06.26.
//

#include <iostream>
#include <string>
#include<unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        vector<int> v('z' - 'a' + 1, 0);
        
        for(auto& c: s1)
            v[c - 'a'] ++;
        
        if(l1 > l2)
            return false;
        for(int i = 0; i < l1; i++)
            v[s2[i] - 'a'] --;
        bool found = true;
        
        for(int i = 0; i < 'z' - 'a' + 1; i++)
        {
            if(v[i] != 0)
            {
                found = false;
                break;
            }
        }
        if (found)
            return true;
        int left = 0, right = l1 -1;
        v[s2[left] - 'a'] ++;
        left++;
        right ++;
        
        while(right < l2)
        {
            v[s2[right] - 'a'] --;
            bool found = true;
            
            for(int i = 0; i < 'z' - 'a' + 1; i++)
            {
                if(v[i] != 0)
                {
                    found = false;
                    break;
                }
            }
            if (found)
                return true;
            
            v[s2[left] - 'a'] ++;
            left ++;
            right ++;
        }
            
        return false;
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.checkInclusion("ab", "eidbaooo");
    return 0;
}
