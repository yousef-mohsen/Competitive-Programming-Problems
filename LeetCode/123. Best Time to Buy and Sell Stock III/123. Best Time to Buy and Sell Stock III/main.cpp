//
//  main.cpp
//  123. Best Time to Buy and Sell Stock III
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
        
        vector<int> end (size , 0);
        vector<int> start (size , 0);
        
        int mn = prices[0];
        for(int i = 1; i < size; i++)
        {
            mn = min (mn, prices[i]);
            end[i] = max(end[i - 1], prices[i] - mn);
        }
        
        int mx = prices[size - 1];
        for(int i = size - 2; i >=0 ; i--)
        {
            mx = max (mx, prices[i]);
            start[i] = max(start[i + 1], mx - prices[i]);
        }
        int sum = end[size - 1];
        for(int i = 0; i < size - 1; i++)
        {
            sum = max(sum, end[i] + start[i + 1]);
            
        }
        sum = max(sum, start[0]);
        return sum;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> test = {2};
    cout<<s.maxProfit(test);
    return 0;
}
