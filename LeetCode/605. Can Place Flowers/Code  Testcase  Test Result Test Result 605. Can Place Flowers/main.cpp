//
//  main.cpp
//  605. Can Place Flowers
//
//  Created by Yousef on 04.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int length = flowerbed.size();
        
        for (int i = 0; i < length; i ++)
        {
            if(flowerbed[i] == 1)
            {
                if(i - 1 >= 0 && flowerbed[i - 1] == 0)
                {
                    flowerbed[i - 1] = -1;
                }
                if(i + 1 < length && flowerbed[i + 1] == 0)
                {
                    flowerbed[i + 1] = -1;
                }
            }
        }
        int count = 0;
        for(int i = 0; i < length; i ++)
        {
            if(flowerbed[i] == 0)
            {
                count++;
                if(i + 1 < length)
                {
                    flowerbed[i + 1] = -1;
                }
            }
                
        }
        return n <= count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    vector<int> test = {1,0,0,0,0,1};
    Solution s;
    cout<<s.canPlaceFlowers(test, 2);
    return EXIT_SUCCESS;
}
