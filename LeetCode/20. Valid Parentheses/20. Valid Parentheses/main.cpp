//
//  main.cpp
//  20. Valid Parentheses
//
//  Created by Yousef on 20.05.26.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        
        stack<char> l;
        for (auto a: s)
        {
            if(a == '(' ||
               a == '{' ||
               a == '['
               )
                l.push(a);
            else
            {
                if (l.size() == 0)
                    return false;
                if(
                   (a == ')' && l.top()!= '(')
                   ||
                   (a == ']' && l.top()!= '[')
                   ||
                   (a == '}' && l.top()!= '{')
                   )
                    return false;
                l.pop();
                
            }
        }
    return l.size() == 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.isValid("");
    return EXIT_SUCCESS;
}
