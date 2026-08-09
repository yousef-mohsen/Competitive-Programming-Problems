//
//  main.cpp
//  2396. Strictly Palindromic Number
//
//  Created by Yousef on 08.08.26.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        
        for(int i = 2; i <= n - 2; i++)
        {
            if(!(isPalindrom(n, i)))
                return false;
        }
    
        return true;
    }
    bool isPalindrom(int n, int b)
    {
        int reversed = 0, original = n;
        while(n)
        {
            reversed = reversed * b + n % b;
            n /= b;
        }
        
        return  original == reversed;
    }
    
};

int main(int argc, const char * argv[]) {
    return EXIT_SUCCESS;
}
