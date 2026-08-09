//
//  main.cpp
//  32. Longest Valid Parentheses
//
//  Created by Yousef on 11.06.26.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int length = s.size();
        stack<int> st;
        vector<int> v(length, 0);
        
        for(int i = 0; i < length; i++)
        {
            if(st.size() == 0 && s[i] == ')')
            {
                v[i] = -1;
                continue;
            }
              
            if(s[i] == '(')
            {
                st.push(i);
                continue;
            }
            if(s[i] == ')')
            {
                int index = st.top();
                v[index] = 2;
                st.pop();
                
            }
        }
        
        int counter = 0, maximum = 0;
        for(int i = 0; i < length; i++)
        {
            if(v[i] == 0 && s[i] == ')')
                continue;
            
            if(v[i] == 0 || v[i] == -1)
            {
                counter = 0;
            }
            else
            {
                counter += 2;
                maximum = max(maximum, counter);
            }
            
        }
        return maximum;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.longestValidParentheses("()(()");
  
    return 0;
}
