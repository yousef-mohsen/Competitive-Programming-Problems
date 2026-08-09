//
//  main.cpp
//  45. Jumbing Game II
//
//  Created by Yousef on 20.05.26.
//

#include <iostream>
#include <vector>
#include <limits>

using namespace  std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        
        vector<int> distance (n,INT_MAX);
        distance[0] = 0;
        
        for (int i = 0; i < n; i++)
            for(int k = 1; k <= nums[i]; k++)
            {
                if (k + i >= n || distance[i] == INT_MAX)
                    break;
                distance[i + k] = min(distance[i + k], 1 + distance[i]);
            }
        return distance[n - 1];
    }
};

int main(int argc, const char * argv[]) {
    vector<int> test = {2};
    Solution s;
    cout<<s.jump(test);
    return EXIT_SUCCESS;
}
