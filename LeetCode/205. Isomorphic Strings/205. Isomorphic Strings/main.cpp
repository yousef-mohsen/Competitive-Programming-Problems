//
//  main.cpp
//  205. Isomorphic Strings
//
//  Created by Yousef on 05.06.26.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int length = t.size();
        //unordered_map<char, char> s_2_t, t_2_s;
        vector<int> s_2_t(128, -1);
        vector<int> t_2_s(128, -1);
        
        for (int i = 0; i < length; i++)
        {
            if(s_2_t[s[i]] == -1 && t_2_s[t[i]] == -1)
            {
                s_2_t[s[i]] = t[i];
                t_2_s[t[i]] = s[i];
                continue;
            }
            if(s_2_t[s[i]] != -1)
            {
                if(s_2_t[s[i]] != t[i])
                    return false;
            }
            
            if(t_2_s[t[i]] != -1)
            {
                if(t_2_s[t[i]] != s[i])
                    return false;
            }
            
                
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
