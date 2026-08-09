//
//  main.cpp
//  3794. Reverse String Prefix
//
//  Created by Yousef on 27.05.26.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reversePrefix(string s, int k) {
        
        reverse(s.begin(), s.begin() + k);
        return s;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
