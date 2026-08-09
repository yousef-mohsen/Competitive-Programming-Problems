//
//  main.cpp
//  136. Single Number
//
//  Created by Yousef on 10.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = nums[0], length = nums.size();
        
        for(int i =  1; i < length; i++)
        {
            sum^= nums[i];
        }
            
        return sum;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
