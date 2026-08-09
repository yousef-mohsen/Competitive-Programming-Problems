//
//  main.cpp
//  28. Find the index of the First Occurrence in a String
//
//  Created by Yousef on 27.05.26.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        auto pos = haystack.find(needle);
        if(pos == string::npos)
            return -1;
        return pos;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
