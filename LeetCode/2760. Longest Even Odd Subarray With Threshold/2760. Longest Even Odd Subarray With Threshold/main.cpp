//
//  main.cpp
//  2760. Longest Even Odd Subarray With Threshold
//
//  Created by Yousef on 05.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int l = 0, r = 0, length = nums.size(), b = 1;
        
        bool test = (nums[0] & 1) == 0 && nums[0] <= threshold;
        
        int  longest = test ? 1: 0;
        
        while(l < length && r < length)
        {
            while(l < length && ((nums[l] & (1)) != 0 || (nums[l] > threshold)))
            {
                l++;
            }
            if(l < length)
            {
                test = (nums[l] & 1) == 0 && nums[l] <= threshold;
                
                if(test)
                {
                    longest = max(longest, 1);
                }
            }
            r = l + 1;
            
            while(r < length && ((nums[r] & 1) != (nums[r - 1] & 1)) && nums[r] <= threshold)
            {
                
                longest = max(longest, r - l + 1);
                r++;
                
            }
            if(r >= length)
                break;
            if(nums[r] > threshold)
            {
                r++;
                l = r;
            }
            else
            {
                l = r;
            }
            
        }
        return longest;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> test;
    test = {1,2};
    
    cout<<s.longestAlternatingSubarray(test, 2);
    return EXIT_SUCCESS;
}
