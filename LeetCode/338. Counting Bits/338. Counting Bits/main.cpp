//
//  main.cpp
//  338. Counting Bits
//
//  Created by Yousef on 10.06.26.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        
        if(n >= 1)
            ans[1] = 1;
        
        for(int i = 2; i <= n; i++)
        {
            if(i & 1)
            {
                ans[i] = 1 + ans[i>>1];
            }
            else
            {
                ans[i] = ans[i >> 1];
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
