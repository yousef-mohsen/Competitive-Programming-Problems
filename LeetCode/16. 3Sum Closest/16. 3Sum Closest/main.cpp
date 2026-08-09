//
//  main.cpp
//  16. 3Sum Closest
//
//  Created by Yousef on 11.06.26.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = INT_MAX, sum = 0;
        
        int length = nums.size();
        
        for(int i = 0; i < length - 2; i++)
        {
            int left = i + 1, right = length - 1;
            while(left < right)
            {
                while(left < right && left> i + 1 && nums[left] == nums[left-1])
                    left ++;
                
                while(left < right && right < length - 1 && nums[right] == nums[right + 1])
                    right --;
                if (left == right)
                    break;
                int temp = abs(nums[i] + nums[left] +nums[right] -target);
                if(temp == 0)
                    return target;
                if(temp < closest)
                {
                    closest = temp;
                    sum = nums[i] + nums[left] + nums[right];
                }
                if(nums[i] + nums[left] + nums[right] < target)
                    left++;
                else
                    right --;
                
            }
        }
                
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> test = {-1,2,1,-4};
    
    s.threeSumClosest(test, 1);
    return 0;
}
