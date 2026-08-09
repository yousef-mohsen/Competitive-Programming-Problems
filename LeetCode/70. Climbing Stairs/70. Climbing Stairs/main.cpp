//
//  main.cpp
//  70. Climbing Stairs
//
//  Created by Yousef on 20.05.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> v(n + 5, 0);
        v[0] = 1;
        for(int i = 0; i< n; i++)
        {
            v[i + 1] += v[i];
            v[i + 2] += v[i];
        }
        return v[n];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
