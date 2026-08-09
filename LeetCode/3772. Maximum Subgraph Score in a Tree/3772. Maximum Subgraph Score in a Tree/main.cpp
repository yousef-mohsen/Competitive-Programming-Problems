//
//  main.cpp
//  3772. Maximum Subgraph Score in a Tree
//
//  Created by Yousef on 29.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        vector<vector<int>> adj_1(n), adj_2(n);
        vector<bool> visited_1 (n, false), visited_2(n, false);
        vector<int> ans (n, -1), p_1(n, -1), p_2(n, -1), ans_1(n, -1), ans_2 (n, -1);
        
        
        
        for(auto e: edges)
        {
            adj_1[e[0]].push_back(e[1]);
            adj_2[e[1]].push_back(e[0]);
        }
        for(int i = 0; i < n; i++)
        {
            if(good[i]){
                ans_1[i] = 1;
                ans_2[i] = 1;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            if(!visited_1[i])
                dfs(i, adj_1, visited_1, ans_1, true, p_1);
        }
        
        for(int i = 0; i < n; i++)
        {
            if(!visited_2[i])
                dfs(i, adj_2, visited_2, ans_2, false, p_1);
        }
        
        for(int i = 0; i < n; i ++)
        {
            ans[i] = ans_1[i];
            bool taken = false;
            if(p_1[i] != -1)
            {
                 if(ans[i] > 0)
                 {
                     
                     if(ans_1[p_1[i]] > ans[i])
                     {
                         ans[i] += ans_1[p_1[i]] - ans[i];
                         taken = true;
                     }
                 }
                else
                {
                    if(ans_1[p_1[i]] > 0)
                    {
                        ans[i] += ans_1[p_1[i]];
                        taken = true;
                    }
                }
                if(ans_2[p_1[i]] > 0)
                {
                    ans[i] += ans_2[p_1[i]];
                    if(taken)
                    {
                        if(!good[p_1[i]])
                            ans[i] ++;
                        else
                            ans[i] --;
                    }
                }
            }
            
        }
        
        return ans;
    }
    void dfs(int n, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans, bool p, vector<int> & parent)
    {
        visited[n] = true;
        
        for(auto v: adj[n])
        {
            if(!visited[v])
                dfs(v, adj, visited, ans, p, parent);
            if(ans[v] >= 1)
                ans[n] += ans[v];
            if(p)
                parent[v] = n;
            
        }
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>> edges = {{1,0},{1,2},{1,3},{3,4}};
    vector<int> good = {0,1,0,1,1};
    s.maxSubgraphScore(5, edges, good);
    return 0;
}
