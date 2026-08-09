//
//  main.cpp
//  3512. Minimum Operations to Make Array Sum Divisible by K
//
//  Created by Yousef on 09.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        
        for(auto n: nums)
            sum += n;
        
        return sum % k;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
