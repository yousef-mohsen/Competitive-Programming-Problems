//
//  main.cpp
//  399. Evaluate Division
//
//  Created by Yousef on 21.05.26.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
   
    //unordered_map<string, double> distance;
    vector<double> distance;
    //unordered_map<string, bool> visited;
    vector<bool> visited;
    //unordered_map<string, vector<pair<string, double>>> adj;
    vector<vector<pair<int, double>>> adj;
    unordered_map<string, int> index;
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        double value = 0.0;
        int ind = 0, u, v;
        
        for(int i = 0; i < equations.size(); i++)
        {
            if(!index.count(equations[i][0]))
            {
                index[equations[i][0]] = ind++;
            }
            if(!index.count(equations[i][1]))
                index[equations[i][1]] = ind++;
        }
        
        adj = vector<vector<pair<int, double>>>(ind);
        
        for (int i = 0; i < equations.size(); i++)
        {
            string start = equations[i][0], end = equations[i][1];
            u = index[start]; v = index[end];
            
            value = values[i];
            adj[u].push_back(make_pair(v, value));
            adj[v].push_back(make_pair(u,1/ value));
        }
        
        vector<double> ans;
        
        for (auto q: queries){
            string start = q[0];
            string end = q[1];
            if(!index.count(start) || !index.count(end))
            {
                ans.push_back(-1);
                continue;
            }
            visited = vector<bool> (ind, false);
            distance = vector<double> (ind, 0);
            u = index[start]; v = index[end];
            
                distance[u] = 1;
                dfs(u);
                if(!visited[v])
                    ans.push_back(-1);
                else
                    ans.push_back(distance[v]);
            }
        
        return ans;
        
    }
    
    void dfs(int s){
        visited[s] = true;
        
        for(auto v: adj[s])
        {
            if(!visited[v.first])
            {
                distance[v.first] = distance[s] * v.second;
                dfs(v.first);
            }
                
        }
    }
};


int main(int argc, const char * argv[]) {
        
    vector<vector<string>> equations(2);
    equations[0].push_back("a");
    equations[0].push_back("b");
    equations[1].push_back("b");
    equations[1].push_back("c");
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries(1);
    queries[0].push_back("a");
    queries[0].push_back("c");
    
    Solution s;
    auto ans= s.calcEquation(equations, values, queries);
    for(auto a: ans)
        cout<<a<<" ";
    
    
    
    return EXIT_SUCCESS;
}
