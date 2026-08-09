//
//  main.cpp
//  75. Sort Colors
//
//  Created by Yousef on 12.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        
        for(auto n: nums)
        {
            if (n == 0)
                red++;
            else if (n == 1)
                white ++;
            else blue ++;
        }
        int counter = 0;
        while (red){
            nums[counter ++] = 0; red--;
        }
        while (white){
            nums[counter ++] = 1; white--;
        }
        while (blue)
        {
            nums[counter ++] = 2; blue--;
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> test = {1};
    Solution s;
    s.sortColors(test);
    return 0;
}
