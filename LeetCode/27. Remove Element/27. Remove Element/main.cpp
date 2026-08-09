//
//  main.cpp
//  27. Remove Element
//
//  Created by Yousef on 09.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        int r = length - 1;
        bool same = true;
        
        for(int i = 0; i < length; i++)
            if(nums[i] != val)
            {
                same = false;
                break;
            }
        if(same)
        {
            nums = {};
            return 0;
        }
        
        for(int i = 0; i < length; i++)
        {
            if (i >= r)
            {
                if(nums[i] == val)
                    return i;
                return i + 1;
            }
                
            if(nums[i] != val)
                continue;
            
            while(r > i && nums[r] == val)
                r--;
            if(r == i)
            {
                if(nums[i] == val)
                    return i;
                return i + 1;
            }
            swap(nums[i], nums[r]);
            r--;
        }
        
        return length;
    }
};

int main(int argc, const char * argv[]) {
    vector <int> test = {2,3,3};
    Solution s;
    cout<<s.removeElement(test, 3);
    return 0;
}
