//
//  main.cpp
//  207. Course Schedule
//
//  Created by Yousef on 08.08.26.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> stats;
    vector<vector<int>> adj;
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int l = prerequisites.size();
        stats = vector<int>(numCourses, 0);
        adj = vector<vector<int>>(numCourses);
        for(int i = 0; i < l; i ++)
        {
            int a =prerequisites[i][0];
            int b =prerequisites[i][1];
            adj[b].push_back(a);
        }
        
        for(int i = 0; i < numCourses; i++)
        {
            if(stats[i] == 0 && adj[i].size() != 0)
            {
                bool ans = dfs(i, adj);
                if(!ans)
                    return false;
            }
            
            
        }
        return true;
    }
    
    bool dfs (int i, vector<vector<int>>& adj)
    {
        for(auto v: adj[i])
        {
            if(stats[v] == 1)
                return false;
            if(stats[v] == 0)
            {
                stats[v] = 1;
                if(!dfs(v, adj))
                    return false;
                stats[v] = 2;
            }
        }
        stats[i]  = 2;
        return true;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> test = {
        {1,0}
    };
    s.canFinish(2, test);
    return EXIT_SUCCESS;
}
