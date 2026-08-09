//
//  main.cpp
//  18. 4Sum
//
//  Created by Yousef on 11.06.26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int length = nums.size();
        if(length < 4)
            return {};
        vector<vector<int>> ans;
    
        
        for(int i = 0; i < length - 3; i++)
        {
            while (i > 0 && nums[i] == nums[i - 1] && i < length - 3)
                i++;
            if (i == length - 3)
                break;
            
            for(int start = i + 1; start < length -2; start++)
            {
                
                while(start > i + 1 && start < length - 2 && nums [start] == nums [start - 1])
                        start ++;
                
                
                if (start == length - 2)
                    break;
                
                int right = length - 1;
                int left = start + 1;
                
                while(left < right)
                {
                    while(left > start + 1 && left < right && nums[left - 1] == nums[left])
                        left++;
                    while(right < length - 1 && left < right && nums[right + 1] == nums[right])
                        right--;
                    if(left == right)
                        break;
                    
                       
                    long long  sum = (long long)nums[i] + nums[start] +nums[left] + nums[right];
                    if(sum == target)
                    {
                        ans.push_back({nums[i], nums[start], nums[left], nums[right]});
                        left ++;
                        right --;
                        continue;
                    }
                    
                    if(sum < target)
                        left ++;
                    else
                        right --;
                    
                }
                
            }
        }
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> test = {2,2,2,2,2};
    
    Solution s;
    s.fourSum(test, 8);
    return EXIT_SUCCESS;
}
