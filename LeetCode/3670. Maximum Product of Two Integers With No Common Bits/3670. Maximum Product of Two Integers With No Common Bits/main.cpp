//
//  main.cpp
//  3670. Maximum Product of Two Integers With No Common Bits
//
//  Created by Yousef on 03.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long maximum = 0, ans = 0;
        
        for(auto n: nums)
        {
            if (n > maximum)
                maximum = n;
        }
        int pos = 0;
        for(int i = 0; i < 20; i ++)
        {
            if((1<<i) & maximum)
                pos = i;
        }
        pos ++;
        int length = 1<<(pos);
        vector<long long> v(length + 1, 0);
        
        for(auto n: nums)
        {
            v[n] = n;
        }
        
        for(int i  = 1; i <= length; i ++)
        {
            for(int k = 0; k <= pos; k++)
            {
                if(i & (1<<k))
                    v[i] = max(v[i ^ (1<<k)], v[i]);
            }
        }
        
        long long full = (1<<pos) - 1;
        for (auto n: nums)
        {
            ans = max(ans, v[full^n] * n);
        }
        
        
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    

    return 0;
}
