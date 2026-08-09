//
//  main.cpp
//  26. Remove Duplicates from Sorted Array
//
//  Created by Yousef on 09.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        int k = 1, r = 1;;
        
        for(int i = 1; i < length; i++)
        {
            while(r < length && nums[r] == nums[i - 1])
                r++;
            if(r == length)
                return k;
            k ++;
            swap (nums[i], nums [r]);
            r ++;
        }
        return k;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> test = {1};
    cout<<s.removeDuplicates(test);
    cout<<"test";
    return 0;
}
