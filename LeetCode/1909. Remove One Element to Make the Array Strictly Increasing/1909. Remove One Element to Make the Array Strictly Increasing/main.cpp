//
//  main.cpp
//  1909. Remove One Element to Make the Array Strictly Increasing
//
//  Created by Yousef on 04.06.26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int count = 0, length = nums.size();
        
        for(int i = 0; i < length; i++)
        {
            if (i + 1 < length)
            {
                if (nums[i] >= nums[i + 1])
                {
                    count ++;
                    if(count >= 2)
                        return false;
                    
                    if(i - 1 >= 0)
                    {
                        if (nums [i - 1] >= nums[i + 1] )
                        {
                            
                            if(i + 2 < length)
                            {
                                if (nums[i] >= nums[i + 2])
                                {
                                    return false;
                                }
                                else
                                {
                                    i++;
                                }
                            }
                        
                        }
                        
                    }
                    
                    
                    
                }
                
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> test = {105,924,32,968};
    cout<<s.canBeIncreasing(test);
    return EXIT_SUCCESS;
}
