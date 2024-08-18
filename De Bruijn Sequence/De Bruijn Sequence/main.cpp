//
//  main.cpp
//  De Bruijn Sequence
//
//  Created by Yousef on 10.11.20.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> c;
vector<vector<pair<int,int>>>adj;
vector<bool> visited;
int r;
void eu (int u)
{
    int t = u<<1;
    int y = t;
    t = t | 1;
    if(!visited[t])
    {
        visited[t] = true;
        c.push_back(1);
        eu(((u<<1)|1) & r);
    }
    if(!visited[y])
    {
       visited[y] = true;
        c.push_back(0);
        eu((u<<1) & r);
    }
    
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, t, end;
    cin>>n;
    if(n == 1)
    {
        cout<<"01";
        return 0;
    }
    end = pow(2, n - 1);
    r = end - 1;
    c = vector<int>();
    visited = vector<bool>(pow(2, n), false);
    for(int i = 0; i < n; i ++)
        c.push_back(0);
    c.push_back(1);
    visited[1] = true;
    visited[0] = true;
    
    adj = vector<vector<pair<int,int>>>(end);
    
    for(int i = 0; i < end; i++)
    {
        t = i;
        t = t<<1;
        t = t & (r);
        adj[i].push_back({t, 0});
        t = t | 1;
        adj[i].push_back({t , 1});
    }
    eu(1);
    for(auto a: c)
        cout<<a;
    
    
    return 0;
}
