//
//  main.cpp
//  118. Pascal's Triangle
//
//  Created by Yousef on 09.06.26.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans (numRows, vector<int>());
        ans[0] = vector<int> (1, 1);
        for(int i = 1; i < numRows; i ++)
        {
            ans[i] = vector<int> (i + 1, 1);
            for(int k = 0; k < i + 1; k++)
            {
                if (k == 0 || k == i)
                    continue;
                ans[i][k] = ans[i- 1][k] + ans[i- 1][k - 1];
            }
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.generate(5);
    return 0;
}
