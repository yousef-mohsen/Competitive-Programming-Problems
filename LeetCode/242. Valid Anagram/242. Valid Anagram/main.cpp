//
//  main.cpp
//  242. Valid Anagram
//
//  Created by Yousef on 10.06.26.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!= t.size())
            return false;
        
        int length = s.size();
        vector<int> v_s('z' - 'a' + 1, 0);
        vector<int> v_t('z' - 'a' + 1, 0);
        
        for(int i = 0; i < length; i++)
        {
            v_s[s[i] - 'a'] ++;
            v_t[t[i] - 'a'] ++;
        }
        
        int l = v_s.size();
        for(int i = 0; i < l; i++)
            if(v_s[i] != v_t[i])
                return false;
        
        return true;
        
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
