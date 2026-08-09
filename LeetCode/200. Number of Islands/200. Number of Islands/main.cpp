//
//  main.cpp
//  200. Number of Islands
//
//  Created by Yousef on 08.08.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> c;
    vector<vector<int>> adj;
    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size(), n = grid[0].size(), l = n * m, counter = 0;
        c = vector<int>(l, -1);
        
        adj = vector<vector<int>> (l, vector<int>());
        for(int i = 0; i < m ; i++)
            for(int k = 0; k < n; k ++)
            {   int pos = i * n + k;
                
                if(k < n - 1 && grid[i][k] == '1' && grid[i][k + 1] == '1')
                {
                    adj[pos].push_back(pos + 1);
                    adj[pos + 1].push_back(pos);
                }
                if(i < m - 1 &&grid[i][k] == '1' && grid[i + 1][k] == '1')
                {
                    adj[pos].push_back(pos + n);
                    adj[pos + n].push_back(pos);
                }
                
            }
        
 
        for (int i = 0; i < l; i++) {
            int row = i / n, column = i % n;
            if (grid[row][column] == '1' && c[i] == -1) {
                counter++;
                dfs(i, grid, counter);
            }
        }
        return counter;
    }
    void dfs(int i, vector<vector<char>> &grid, int &counter) {
        c[i] = counter;
        for(auto v: adj[i])
        {
            if(c[v] == -1)
            {
                dfs(v, grid, counter);
            }
        }
        /*
        if (column < n - 1 && grid[row][column + 1] == '1' && c[i + 1] == -1) {
            dfs(row, column + 1, i + 1, m, n, grid, counter);
        }
        if (row < m - 1 && grid[row + 1][column] == '1' && c[i + n] == -1) {
            dfs(row + 1, column, i + n, m, n, grid, counter);
        }
         */
    }
};

int main(int argc, const char *argv[]) {
    // insert code here...
    vector<vector<char>> test = {
        {{'1','1','1'},{'0','1','0'},{'1','1','1'}}
    }
    
    
    ;
    Solution s;
    cout<<s.numIslands(test);
    return EXIT_SUCCESS;
}
