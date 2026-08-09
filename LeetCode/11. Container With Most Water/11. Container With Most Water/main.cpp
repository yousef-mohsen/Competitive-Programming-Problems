//
//  main.cpp
//  11. Container With Most Water
//
//  Created by Yousef on 03.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0, l = 0, r = height.size() - 1;
        
        while (l != r)
        {
            area = max (area, (r-l) * min(height[l], height[r]));
            if(height[l] < height[r])
                l ++;
            else
                r--;
        }
        return area;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector v = {8,7,2,1};
    cout<<s.maxArea(v);
    
    return 0;
}
