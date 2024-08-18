//
//  main.cpp
//  C. Cut 'em all!
//
//  Created by Yousef on 24.07.20.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


stack<int> s;

s.

long long counter = 0;
vector <bool> visited;
vector <long long> size;
vector<vector<int>> adj;

void dfs(int a)
{
    
    visited[a] = true;
    
    for(auto n:adj[a])
    {
        if(!visited[n])
        {
        dfs(n);
        size[a] += size[n];
        }
    }
    if((size[a] ^ 1) == (size[a] + 1))
    {
        counter ++;
    }
    
    
}


int main(int argc, const char * argv[]) {
    int n, a, b;
    cin>>n;
    visited = vector<bool>(n + 1, false);
    size = vector <long long >(n + 1, 1);
    adj = vector<vector<int>>(n + 1);
    
    for(int i = 0; i < n - 1; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(a);
    
    if (size[a] %2 == 1)
    {
        cout <<-1;
        return 0;
    }
    

    cout<<counter - 1;
    
    return 0;
}
