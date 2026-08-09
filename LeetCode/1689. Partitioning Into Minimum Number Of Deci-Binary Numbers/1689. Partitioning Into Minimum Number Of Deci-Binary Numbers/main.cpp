//
//  main.cpp
//  1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
//
//  Created by Yousef on 28.05.26.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int maximum = 0;
        for (const auto& d: n)
        {
            maximum = max(maximum, d-'0');
            if(maximum == 9)
                return 9;
        }
        return maximum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
