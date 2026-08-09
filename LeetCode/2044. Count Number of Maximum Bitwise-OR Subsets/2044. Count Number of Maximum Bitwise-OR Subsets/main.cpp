//
//  main.cpp
//  2044. Count Number of Maximum Bitwise-OR Subsets
//
//  Created by Yousef on 08.08.26.
//

#include <iostream>
#include <vector>

using namespace  std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max = nums[0], l = nums.size(), ans = 0;
        
        for(int i = 0; i < l; i++)
        {
            max |= nums[i];
        }
        int s = (1 << l) - 1;
        
        for(int i = 1; i <= s; i ++)
        {
            int sum = 0;
            for(int k = 0; k < l; k ++)
            {
                if(i & (1<<k))
                    sum|=nums[k];
                if(sum == max)
                    break;
            }
            if (sum == max)
                ans++;
        }
        
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums = {3, 1};
    
    s.countMaxOrSubsets(nums);
    
    return EXIT_SUCCESS;
}
