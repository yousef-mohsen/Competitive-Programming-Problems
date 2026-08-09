//
//  main.cpp
//  3898. Find the Degree of Each Vertex
//
//  Created by Yousef on 09.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        
        
        int size = matrix.size();
        vector<int> ans (size, 0);
        
        for(int i = 0; i < size; i++)
        {
            int count = 0, s = matrix[i].size();
            for(int k = 0; k < s; k++ )
            {
                if(matrix[i][k])
                    count ++;
            }
            ans[i] = count;
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
