//
//  main.cpp
//  52. N-Queens II
//
//  Created by Yousef on 02.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> diagonal_1;
    vector<bool> diagonal_2;
    vector<bool> column;
    int count = 0;
    int totalNQueens(int n) {
        
        diagonal_1 = vector<bool> (2 * n, false);
        diagonal_2 = vector<bool> (2 * n, false);
        column = vector<bool> (n, false);
        
        solve(0, n);
        return count;
        
    }
    void solve (int current, int n)
    {
        if (current == n)
        {
            count ++;
            return;
        }
        for(int i = 0; i < n; i++)
        {
            if(diagonal_1[i + current] || diagonal_2[i - current + n - 1] || column[i])
                continue;
            diagonal_1[i + current] = diagonal_2[i - current + n - 1] = column[i] = 1;
            solve (current + 1, n);
            diagonal_1[i + current] = diagonal_2[i - current + n - 1] = column[i] = 0;
        }
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.totalNQueens(16);
    return 0;
}
