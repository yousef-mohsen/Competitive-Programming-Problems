//
//  main.cpp
//  219. Contains Duplicate II
//
//  Created by Yousef on 10.06.26.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        multiset<int> s;
        int length = nums.size();
        
        for(int i = 0; i < length; i++)
        {
            if(s.size() <= k)
            {
                if(s.count(nums[i]))
                    return true;
                s.insert(nums[i]);
            }
            else
            {
                s.erase(s.find(nums[i - (k + 1)]));
                if(s.count(nums[i]))
                    return true;
                s.insert(nums[i]);
            }
        }
    
        return false;
    
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
