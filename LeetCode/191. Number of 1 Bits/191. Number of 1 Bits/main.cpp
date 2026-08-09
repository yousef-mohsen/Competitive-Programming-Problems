//
//  main.cpp
//  191. Number of 1 Bits
//
//  Created by Yousef on 10.06.26.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        
        for(int i = 0; i < 32; i ++)
        {
            if((1<<i) & n)
                count++;
            if((1<<i) > n)
                break;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
