//
//  main.cpp
//  3857. Minimum Cost to Split into Ones
//
//  Created by Yousef on 03.06.26.
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minCost(int n) {
        vector<long long> v (n + 1, INT_MAX);
        v[1] = 0;
        
        for(int i = 2; i <= n; i ++)
        {
            for(int k = i - 1; k >= i/2; k --)
            {
                long long value = (k)*(i - k) + v[k] + v[i - k];
                v[i] = min (v[i], value);
            }
        }
        return v[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.minCost(500);

    return 0;
}
