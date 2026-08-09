//
//  main.cpp
//  119. Pascal's Triangle II
//
//  Created by Yousef on 10.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> ans (rowIndex + 1, 1);
        
        for(int i = 1; i <= rowIndex; i++)
        {
            for(int k = i - 1; k >= 1; k--)
            {
                ans[k] = ans[k] + ans[k - 1];
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.getRow(0);
    return 0;
}
