//
//  main.cpp
//  53. Maximum Subarray
//
//  Created by Yousef on 12.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = INT_MIN,  sum = 0;
        
        for(auto n: nums)
        {
            sum += n;
            sum = max (sum, n);
            maximum = max(maximum, sum);
        }
        return maximum;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
