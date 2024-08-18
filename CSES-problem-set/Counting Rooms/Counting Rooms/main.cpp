//
//  main.cpp
//  Counting Rooms
//
//  Created by Yousef on 02.03.20.
//  Copyright © 2020 Yousef. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void dfs (bool * found, vector<int> * adj, int s)
{
    if(!found[s])
    {
        found[s] = true;
        for(auto n: adj[s])
        {
            dfs(found, adj, n);
        }
    }
}

int main(int argc, const char * argv[]) {
     ios::sync_with_stdio(0); cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    char ** arr = new char * [n];
    for(int i = 0; i <n; i++)
    {
        arr[i] = new char [m];
    }
     
    vector <int> adj[ n * m + 1];
    char *dummy = new char [n * m + 1];
    long long value = 1;
    
    for(int i = 0; i < n; i++)
    {
        for(int k = 0; k < m; k++)
        {
            cin>>arr[i][k];
            dummy[value++] = arr[i][k];
            
            if(k > 0 && arr[i][k] == '.')
            {
                if (arr[i][k - 1] == '.')
                {
                   adj[m * i + k + 1].push_back(m * i + k);
                   adj[m  * i + k ].push_back(m  * i + k + 1);
                }
            }
            if( i > 0 && arr[i][k] == '.')
            {
                if(arr[i - 1][k] == '.')
                {
                    adj[m  * i + k + 1].push_back(m * (i - 1) + k + 1 );
                    adj[m * (i - 1) + k + 1 ].push_back(m  * i + k + 1);
                }
            }
            
        }
    }
    
    bool * found = new bool [n * m + 1]{false};
    long long counter = 0;
    
    for(int i = 1; i<= n * m; i++)
    {
    
        if(!found [i] && dummy[i] =='.')
        {
            counter ++;
            dfs (found, adj, i);
        }
        
    }
    cout<<counter;
    
    return 0;
}
