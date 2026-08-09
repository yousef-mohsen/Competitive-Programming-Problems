//
//  main.cpp
//  5. Longest Palindromic Substring
//
//  Created by Yousef on 13.06.26.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int start = 0, end = 1;
    string longestPalindrome(string s) {
        int length = s.size(), current = 1;
        
        for(int i = 0; i < length; i++)
            for(int k = i + current; k < length; k++)
            {
             if(is_palindrom(i, k, s))
             {
                 if(k - i + 1 > current)
                 {
                     current = k - i + 1;
                     start = i;
                     end = k;
                 }
                     
             }
            }
        return s.substr(start, current);
    }
    bool is_palindrom(int i, int k, string & s)
    {
        while (i < k)
        {
            if(s[i] != s[k])
                return false;
            i++;
            k --;
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.longestPalindrome("bb");
    return 0;
}
