//
//  main.cpp
//  122. Best Time to Buy and Sell Stock II
//
//  Created by Yousef on 25.06.26.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
      /*
        vector<int> mx(size + 1, 0);
        int m = 0;
        for(int i = size - 2; i >= 0; i--)
        {
            for(int k = i; k < size; k ++)
            {
                mx[i] = max(mx[i], mx[k + 1] + prices[k] - prices[i]);
            }
            
        }
        return mx[0];
    }
    */
        int sum = 0;
        for(int i = 0; i < size - 1; i++)
            if(prices[i + 1] > prices [i])
                sum+= prices[i+1] - prices[i];
        return sum;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> test = {3,2,6,5,0,3};
    cout<<s.maxProfit(test);
    return 0;
}
