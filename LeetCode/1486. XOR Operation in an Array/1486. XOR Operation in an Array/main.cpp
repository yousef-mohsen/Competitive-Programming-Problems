//
//  main.cpp
//  1486. XOR Operation in an Array
//
//  Created by Yousef on 09.06.26.
//

#include <iostream>


class Solution {
public:
    int xorOperation(int n, int start) {
        int sum = start;
        
        for (int i = 1; i < n; i ++)
            sum ^= start + 2 * i;
            
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
