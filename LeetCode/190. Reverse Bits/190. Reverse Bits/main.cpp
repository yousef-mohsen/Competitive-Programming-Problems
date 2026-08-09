//
//  main.cpp
//  190. Reverse Bits
//
//  Created by Yousef on 10.06.26.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        
        for(int i = 0; i < 32; i++)
        {
            if(n &(1<<i))
                ans+= (1<<(31-i));
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
