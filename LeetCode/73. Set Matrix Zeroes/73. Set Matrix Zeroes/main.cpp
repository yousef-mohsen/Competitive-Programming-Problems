//
//  main.cpp
//  73. Set Matrix Zeroes
//
//  Created by Yousef on 13.06.26.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool row = false, column = false;
        
        for(int i = 0; i < m; i++)
            for(int k = 0; k < n; k++)
            {
             if(matrix[i][k] == 0)
             {
                 matrix[0][k] = 0;
                 matrix[i][0] = 0;
                 if(i == 0)
                     row = true;
                 if(k == 0)
                     column = true;
                 
             }
            
            }
        for(int i = 1; i < m; i++)
        {
            if(matrix[i][0] == 0)
            {
                for(int k = 1; k < n; k++)
                {
                    matrix[i][k] = 0;
                }
            }
        }
        for(int i = 1; i < n; i++)
        {
            if(matrix[0][i] == 0)
            {
                for(int k = 1; k < m; k++)
                {
                    matrix[k][i] = 0;
                }
            }
        }
        if(row)
        {
            for(int i = 0; i < n; i++)
            {
                matrix[0][i] = 0;
            }
        }
        if(column)
        {
            for(int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
        
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> test = {
        {1,2,3,4},
        {5,0,7,8},
        {0,10,11,12},
        {13,14,15,0}
    };
    s.setZeroes(test);
    return 0;
}
