//
//  main.cpp
//  Giant Pizza
//
//  Created by Yousef on 05.11.20.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<vector<int>> adj;
vector<vector<int>> adjr;
vector<bool> visited;
vector<bool> visitedr;
vector<int> order;

stack <int> s;

int pos(int a)
{
    if(a < 0)
        return a * -2;
    else
        return (a * 2) - 1;
}
void dfs(int a)
{
    visited[a] = true;
    for(auto q: adj[a])
        if(!visited[q])
            dfs(q);
    s.push(a);
}
void dfs2(int a, int o)
{
    visitedr[a] = true;
    order[a] = o;
    for(auto q: adjr[a])
        if(!visitedr[q])
            dfs2(q, o);
    
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, b ,t;
    char c;
    cin>>n>>m;
    t = 2 * m + 1;
    
    adj = vector<vector<int>>(t, vector<int>());
    visited = vector<bool>(t, false);
    visitedr = vector<bool>(t, false);
    adjr = vector<vector<int>>(t, vector<int>());
    order = vector<int> (t, 0);
    for(int i = 1; i <= n; i++)
    {
        cin>>c>>a;
        if(c =='-')
            a*= -1;
        cin>>c>>b;
        if(c =='-')
        b*= -1;
        adj[pos(-a)].push_back(pos(b));
        adj[pos(-b)].push_back(pos(a));
    }
    for (int i = 1; i < t; i++)
    {
        if(!visited[i])
            dfs(i);
    }
    for(int i = 1; i < t; i++)
    {
        if(adj[i].size() >= 1)
            for(auto q: adj[i])
                adjr[q].push_back(i);
    }
    int counter = 0;
    while(s.size() > 0)
    {
        int r = s.top();
        s.pop();
        if(!visitedr[r])
        {
            counter ++;
            dfs2(r, counter);
        }
    }
    vector<bool> solution;
    for(int i = 1; i < t; i += 2)
    {
        if(order[i] == order[i + 1])
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
        if(order[i] > order[i + 1])
            solution.push_back(true);
        else
            solution.push_back(false);
    }
    for(auto t: solution)
    {
        if(t == 0)
            cout<<"- ";
        else
            cout<<"+ ";
    }
    return 0;
}
