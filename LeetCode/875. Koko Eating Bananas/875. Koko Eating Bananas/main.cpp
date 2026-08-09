//
//  main.cpp
//  875. Koko Eating Bananas
//
//  Created by Yousef on 08.08.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int x  = 0, l = piles.size(),  maxi = 0;
        
        for(int i = 0; i < l; i++)
            maxi = max(maxi, piles[i]);
        
        for(; maxi>= 1; maxi/=2)
        {
            while(!solvable(maxi + x, h, piles))
            {
                x+= maxi;
            }
        }
        return x + 1;
    }
    bool solvable(int n, int h, vector<int>& piles)
    {
        long long sum = 0, l = piles.size();
        for(int i = 0; i < l; i++)
        {
            sum+= (piles[i] + n - 1)/n;
        }
        if(sum <= h)
            return true;
        return false;
    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> test = {1000000000,1000000000};
    s.minEatingSpeed(test, 3);
    return EXIT_SUCCESS;
}
