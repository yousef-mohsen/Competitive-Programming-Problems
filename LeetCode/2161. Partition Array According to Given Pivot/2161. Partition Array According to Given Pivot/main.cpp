//
//  main.cpp
//  2161. Partition Array According to Given Pivot
//
//  Created by Yousef on 08.08.26.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int length = nums.size(), count = 0, pos = 0;
        vector<int> ans (length);
        for(int i = 0; i < length; i++)
        {
            if(nums[i] < pivot)
            {
                ans[pos++] = nums[i];
            }
            else if (nums[i] == pivot)
            {
                count ++;
            }
            
        }
        while(count)
        {
            ans[pos++] = pivot;
            count--;
        }
        
        for(int i = 0; i < length; i++)
        {
            if(nums[i] > pivot)
            {
                ans[pos++] = nums[i];
            }
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> test = {-1};
    s.pivotArray(test, -1);
}
