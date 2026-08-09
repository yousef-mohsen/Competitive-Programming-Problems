//
//  main.cpp
//  3760. Maximum Substrings With Distinct Start
//
//  Created by Yousef on 28.05.26.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxDistinct(string s) {
        
        vector<int> v ('z' - 'a' + 1, 0);
        int counter = 0;
        for (auto const & c: s)
        {
            if(v[c - 'a'] == 0)
            {
                v[c - 'a'] ++;
                counter ++;
            }
            if(counter == 26)
                return 26;
        }
        
        return counter;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
