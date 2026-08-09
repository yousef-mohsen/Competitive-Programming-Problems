//
//  main.cpp
//  74. Search a 2D Matrix
//
//  Created by Yousef on 13.06.26.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int x = -1, m = matrix.size(), n = matrix[0].size();
        
        for(int b = m; b >= 1; b /= 2)
        {
         while(b + x < m && matrix[b + x][0] <= target)
         {
             x = b + x;
         }
             
        }
        if(x == - 1)
            return false;
        if(matrix[x][0] == target)
            return true;
        
        int z = -1;
        for(int b = n; b >= 1; b /= 2)
        {
            while(b + z < n && matrix[x][b + z] <= target)
                z += b;
        }
        if(z == -1 || matrix[x][z] != target)
            return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> test = {{1,3,5,7},
        {10,11,16,20},
        {23,30,34,50}
    };
    cout<<s.searchMatrix(test, 11);
    return 0;
}
