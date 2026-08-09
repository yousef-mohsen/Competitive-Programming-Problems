//
//  main.cpp
//  15. 3Sum
//
//  Created by Yousef on 11.06.26.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include<set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int length = nums.size(), sum = 0;;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < length - 2; i ++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int left = i + 1, right = length - 1;
            int sum = 0 - nums[i];
            while(left < right)
            {
                if(nums[left] + nums[right] == sum)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++; right --;
                    
                    while (left < right &&nums[left] == nums[left - 1])
                    {
                        left ++;
                    }
                    while (left < right &&nums[right] == nums[right + 1])
                    {
                        right --;
                    }
                }
                else if (nums[left] + nums[right] < sum)
                {
                    left ++;
                }
                else
                {
                    right --;
                }
                
                   
            }
            }
            
                
        return ans;
        }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> test = {-2,0,1,1,2};
    s.threeSum(test);
    return 0;
}
