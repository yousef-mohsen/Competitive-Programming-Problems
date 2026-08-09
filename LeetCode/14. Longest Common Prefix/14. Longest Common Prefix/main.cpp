//
//  main.cpp
//  14. Longest Common Prefix
//
//  Created by Yousef on 09.06.26.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int length = strs.size();
        string ans= "";
        char c ;
        
        for(int i = 0; i < 201; i++)
        {
            if(strs[0].size() <= i)
                return ans;
            c = strs[0][i];
            for(int k = 0; k < length; k ++)
            {
                if(strs[k].size() <= i)
                    return ans;
                if(strs[k][i] != c)
                    return ans;
            }
            ans += c;
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
