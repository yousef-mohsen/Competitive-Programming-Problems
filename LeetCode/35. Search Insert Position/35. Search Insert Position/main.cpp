//
//  main.cpp
//  35. Search Insert Position
//
//  Created by Yousef on 09.06.26.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = -1, length = nums.size();
        int z = max(1, length/2);
        for(z; z >= 1; z/= 2)
        {
            while(ans + z < length && nums[ans + z] < target)
                ans += z;
        }
        
        return ans + 1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> test = {1};
    
    cout<<s.searchInsert(test, 2);
    return 0;
}
