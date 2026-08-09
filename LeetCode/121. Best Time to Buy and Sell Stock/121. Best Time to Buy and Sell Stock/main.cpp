//
//  main.cpp
//  121. Best Time to Buy and Sell Stock
//
//  Created by Yousef on 10.06.26.
//

#include <iostream>
#include<vector>
#include <stack>


using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = 0, ma = prices[0], length = prices.size();
        
        
        for(int i = 1; i < length; i++)
        {
            if(prices[i] > ma)
            {
                m = max(m, prices[i] - ma);
                
            }
            else
            {
                ma = prices[i];
            }
                
        }
        
        return m;
    }
};


int main(int argc, const char * argv[]) {

    return 0;
}
