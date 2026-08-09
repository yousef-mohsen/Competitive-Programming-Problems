//
//  main.cpp
//  51. N-Queens
//
//  Created by Yousef on 24.06.26.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<bool> column;
    vector<bool> diag1;
    vector<bool> diag2;
    vector<vector<string>> ans;
    
    vector<vector<string>> solveNQueens(int n) {
        column = vector<bool> (n ,false);
        diag1 = vector<bool> (2 * n - 1 ,false);
        diag2 = vector<bool> (2 * n - 1,false);
        
        vector<string> s;
        solve (0, n, s);
        return ans;
        
    }
    
    void solve(int q, int n, vector<string> & s)
    {
        if(q ==  n)
        {
            ans.push_back(s);
        }
        
        for(int i = 0; i < n; i ++)
        {
            if(!column[i] && !diag1[i + q] && !diag2[q - i + n - 1])
            {
                column[i] = diag1[i + q] = diag2[q - i + n - 1] = 1;
                string ss = string(n, '.');
                ss[i] = 'Q';
                s.push_back(ss);
                solve (q + 1, n, s);
                s.pop_back();
                column[i] = diag1[i + q] = diag2[q - i + n - 1] = 0;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
