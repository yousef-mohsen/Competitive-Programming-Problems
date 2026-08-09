//
//  main.cpp
//  125. Valid Palindrome
//
//  Created by Yousef on 27.05.26.
//

#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size();
        while(l< r)
        {
            if(!isalnum(s[l]))
                {
                    l ++;
                    continue;
                }
            if(!isalnum(s[r]))
                {
                    r --;
                    continue;
                }
            if(tolower(s[l]) != tolower(s[r]))
            {
                return false;
            }
            l++, r--;
            
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
