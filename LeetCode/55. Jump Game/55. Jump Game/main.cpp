//
//  main.cpp
//  55. Jump Game
//
//  Created by Yousef on 12.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        int max_index = nums[0];
        
        for(int i = 1; i < length; i++)
        {
            if(max_index >= length -1)
                return true;
            if (i > max_index)
                return false;
            max_index = max(max_index, i + nums[i]);
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> test = {0};
    cout<<s.canJump(test);
  
    return 0;
}
