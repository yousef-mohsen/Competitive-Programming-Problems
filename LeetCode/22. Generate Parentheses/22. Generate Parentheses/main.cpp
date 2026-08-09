//
//  main.cpp
//  22. Generate Parentheses
//
//  Created by Yousef on 21.06.26.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int left = 0, right = 0;
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string s = "";
        generate(0, 0, s, n);
        return ans;
    }
    void generate(int left, int right, string & s, int n)
    {
        if(left + right == 2 * n)
        {
            ans.push_back(s);
        }
        else
        {
            
            if(left < n)
            {
                s.push_back('(');
                generate(left + 1, right, s, n);
                s.pop_back();
                
            }
            
            if(right < n && right < left)
            {
                s.push_back(')');
                generate(left, right + 1, s, n);
                s.pop_back();
            }
            
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    return 0;
}
