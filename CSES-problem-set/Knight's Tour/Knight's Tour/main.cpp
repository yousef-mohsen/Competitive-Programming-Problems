//
//  main.cpp
//  Knight's Tour
//
//  Created by Yousef on 24.12.20.
//

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> b(9,vector<int>(9,0));
vector<vector<pair<int,int>>> adj(65,vector<pair<int, int>>());
vector<pair<int, int>> pos;
vector<bool> visited(65,false);
bool solved  = false;

void solve (int p, int counter)
{
    counter ++;
    visited[p] = true;
    b[pos[p].first][pos[p].second] = counter;
    if(counter == 64)
    {
        solved  =true;
        return;
    }
    
    for(auto a: adj[p])
    {
        if(visited[a.second])
            continue;
        if(solved)
            return;
        solve(a.second,counter);
    }
    visited[p] = false;
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int x, y;
    cin>>x>>y;
    vector<pair<int, int>>p;
    vector<int> one = {1,-1};
    vector<int> two = {2,-2};
    for(auto o: one)
        for(auto t: two)
        {
            p.push_back(make_pair(o, t));
            p.push_back(make_pair(t, o));
        }
    pos = vector<pair<int,int>> (65);
    int counter = 1;
    for(int x = 1; x <=8; x++)
        for(int y = 1; y <= 8; y++)
    {
        pos[counter] = {x, y};
        counter ++;
    }

    for(int y = 1; y < 9; y++)
        for(int x = 1; x < 9; x++)
        {
            int nu = (y - 1)*8 + x;
            for(auto t: p)
            {
                if(t.first + x < 1 || t.first + x> 8)
                    continue;
                if(t.second + y < 1 || t.second + y > 8)
                    continue;
                int position = nu + t.second* 8 + t.first;
                adj[nu].push_back({0,position});
            }
        }
    
    for(int i = 1; i <= 64; i++)
    {
        for (auto &t: adj[i])
        {
                t.first = adj[t.second].size();
            
        }
        sort(adj[i].begin(), adj[i].end());
    }
    int start = x + (y - 1)* 8;
    
    solve(start , 0);
    
    for(int i = 1; i< 9; i++)
    {
        for(int k = 1; k < 9; k++)
        {
            cout<<b[i][k]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
