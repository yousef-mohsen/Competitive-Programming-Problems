//
//  main.cpp
//  441. Arranging Coins
//
//  Created by Yousef on 05.06.26.
//

#include <iostream>
#include <math.h>
#include<climits>

using namespace std;
class Solution {
public:
    int arrangeCoins(int n) {
        
        
        return (-1 + sqrt(1 + 8LL * n))/2;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    for(int i = 1; i< 200; i ++)
        s.arrangeCoins(i);
    return 0;
}
