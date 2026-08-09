//
//  main.cpp
//  2144. Minimum Cost of Buying Candies With Discount
//
//  Created by Yousef on 01.06.26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater <int> ());
        int sum = 0, length = cost.size();
        
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            if (count == 2)
            {
                count = 0;
                continue;
            }
            count ++;
            sum += cost[i];
        }
        
        return sum;
    }
    
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> v = {10,5,9,4,1,9,10,2,10,8};
    
    cout<<s.minimumCost(v);

    return 0;
}
