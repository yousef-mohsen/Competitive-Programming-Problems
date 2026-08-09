//
//  main.cpp
//  169. Majority Element
//
//  Created by Yousef on 10.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int length = nums.size(), count = 0, c = 0;
    
        for (int i = 0; i < length; i++)
        {
            if (count == 0)
            {
                c = nums[i];
                count = 1;
            }
            else if(nums[i] != c)
            {
                count --;
            }
            else
            {
                count ++;
            }
        }
        return c;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
