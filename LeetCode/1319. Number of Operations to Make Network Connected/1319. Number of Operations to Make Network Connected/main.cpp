//
//  main.cpp
//  1319. Number of Operations to Make Network Connected
//
//  Created by Yousef on 08.08.26.
//

#include <iostream>
#include <vector>
using namespace std;

/*class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int l = connections.size();
        vector<vector<int>> adj (n);
        if(l < n - 1)
            return -1;


        for(int i = 0; i < l; i ++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> visited (n, false);
        dfs(0, visited, adj);
        int count = 0;
        for(int i = 1; i < n; i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i, visited, adj);
            }
        }

        return count;

    }
    void dfs(int n, vector<bool> & visited, vector<vector<int>> & adj)
    {
        for(auto v: adj[n])
        {
            if(!visited[v])
            {
                visited[v] = true;
                dfs(v, visited, adj);
            }
        }
    }
};
 */

class Solution {
  public:
    vector<int> size;
    vector<int> link;
    int makeConnected(int n, vector<vector<int>> &connections) {
        size = vector<int>(n, 1);
        link = vector<int>(n);
        int l = connections.size(), count = 0;
        if (l < n - 1)
            return -1;

        for (int i = 0; i < n; i++) {
            link[i] = i;
        }
        for (int i = 0; i < l; i++) {
            unite(connections[i][0], connections[i][1]);
        }

        for (int i = 0; i < n; i++) {
            if (find(i) != find(0)) {
                unite(0, i);
                count++;
            }
        }

        return count;
    }
    int find(int a) {
        if (a == link[a])
            return a;
        return link[a] = find(link[a]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (size[a] < size[b])
            swap(a, b);
        size[a] += size[b];
        link[b] = a;
    }
};

int main(int argc, const char *argv[]) {
    vector<vector<int>> test = {{0, 1}, {0, 2}, {3, 4}, {2, 3}};
    Solution s;
    s.makeConnected(5, test);
}
