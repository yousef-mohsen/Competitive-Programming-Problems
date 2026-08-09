//
//  main.cpp
//  217. Contains Duplicate
//
//  Created by Yousef on 10.06.26.
//

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        
        sort(nums.begin(), nums.end());
        int length = nums.size();
        
        for (int i = 0; i < length - 1; i ++)
            {
             if( nums[i] == nums[i + 1])
                 return true;
            }
        
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
