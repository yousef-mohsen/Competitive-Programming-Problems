//
//  main.cpp
//  41. First Missing Positive
//
//  Created by Yousef on 23.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int size = nums.size();
        
        for(int i = 0; i < size; i ++)
        {
            if(nums[i] <= 0 || nums[i] >= size)
                continue;
            if(nums[i] != i + 1)
            {
                if(nums[i] != nums[nums[i] - 1])
                {
                    swap(nums[i], nums[nums[i] - 1]);
                    i--;
                }
            }
            
        }
        
        for(int i = 0; i < size; i ++)
        {
            if(nums[i] != i + 1)
                return i + 1;
        }
        return size + 1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> test = {1,1,3};
    cout<<s.firstMissingPositive(test);
    return 0;
}
