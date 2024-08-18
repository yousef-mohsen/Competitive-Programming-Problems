//
//  main.cpp
//  C. Cut 'em all!
//
//  Created by Yousef on 24.07.20.
//

#include <iostream>
#include <vector>
using namespace std;

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
}

void count (int a)
{

    visited[a] = true;
    
    for(auto n:adj[a])
    {
        if(!visited[n] && (size[n] ^ 1) == (size[n] + 1))
        {
            counter ++;
            
        }
        if(!visited[n])
        {
        count(n);
        }
        
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
    
    visited = vector<bool>(n + 1, false);
    count(a);
    cout<<counter;
    
    return 0;
}
