//
//  main.cpp
//  980. Unique Paths III
//
//  Created by Yousef on 01.06.26.
//

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


class Solution {
public:
    vector<tuple<int, int, int>> v;
    vector<int> visited;
    vector<vector<int>> adj;
    int ans = 0, length = 0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), start = 0, end, id = 0;        visited = vector<int> (n * m, 0);
        adj = vector<vector<int>> (n * m, vector<int>());
        for(int i = 0; i < m; i ++)
            for(int k = 0; k < n; k++)
            {
                if(grid[i][k] == -1)
                {
                    visited[i * n + k] = - 1;
                    continue;
                }
                if(grid[i][k] == 2)
                {
                    end = i * n + k;
                    length ++;
                        continue;
                }
                
                if(grid[i][k] == 1)
                {
                    start = i * n + k;
                    
                }
                length ++;
               
                id = i * n + k;
                if(k - 1 > -1)
                {
                    if(grid[i][k - 1] != -1 && grid[i][k - 1]!= 1)
                        adj[id].push_back(i * n + k - 1);
                }
                    
                if(k + 1 < n)
                {
                    if(grid[i][k + 1] != -1 && grid[i][k + 1]!= 1)
                        adj[id].push_back(i * n + k + 1);
                }
                    
                if(i + 1 < m)
                {
                    if(grid[i + 1][k] != -1 && grid[i + 1][k]!= 1)
                        adj[id].push_back((i + 1)* n + k);
                }
                    
                if(i - 1 > - 1)
                {
                    if(grid[i - 1][k] != -1 && grid[i - 1][k]!= 1)
                        adj[id].push_back((i - 1)* n + k);
                }
                    
                
                
            }
        visited[start] = true;
        
        dfs(start, end, 1);
        
        
        return ans;
    }
    
    void dfs (int start, int end, int traversed)
    {
        if(start == end && traversed == length)
        {
            ans ++;
            return;
        }
        
        for(auto a: adj[start])
        {
            if(!visited[a])
            {
                visited[a] = 1;
                dfs(a, end, traversed + 1);
                visited[a] = 0;
                
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> grid= {
        {1,0,0,0},
        {0,0,0,0},
        {0,0,2,-1}
        
    };
    cout<<s.uniquePathsIII(grid);
    return EXIT_SUCCESS;
}
