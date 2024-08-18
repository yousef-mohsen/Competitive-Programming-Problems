//
//  main.cpp
//  Labyrinth
//
//  Created by Yousef on 08.03.20.
//  Copyright © 2020 Yousef. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main(int argc, const char * argv[]) {
    
    
    ios::sync_with_stdio(0); cin.tie(0);

    int a = 0;
    int b = 0;
    int n, m;
    long long inf = 1e13;
    
    cin>>n>>m;
    
    long long * distance = new long long[n * m + 1];
    char ** arr = new char* [n + 1];
    bool * processed = new bool [n * m + 1];
    int * parent = new int [n * m + 1];
    
    for(int i =0; i < n*m+1; i++)
    {
        distance[i] = 0;
        processed [i] = false;
        
    }
    
  
   
    
    for(int i = 1; i <= n ; i++)
    {
        arr[i] = new char [m + 1];
    }
    vector <int> * adj = new vector<int> [n * m + 1];
    
    
    for(int i = 1; i <= n; i++)
        for(int k = 1; k<= m; k++)
        {
            
            cin>>arr[i][k];
            
            if(arr[i][k] == 'A')
            {
                a = (i - 1) * m + k;
                arr[i][k] = '.';
            }
            if(arr[i][k] == 'B')
            {
                b = (i - 1) * m + k;
            arr[i][k] = '.';
                
            }
            if(i >= 2 && arr[i][k] =='.' && arr[i - 1][k] == '.')
            
            {
                adj[(i - 1) * m + k].push_back((i - 2) * m + k);
                adj[(i - 2) * m + k].push_back((i - 1) * m + k);
            }
            
            if(k>=2 && arr[i][k] =='.' && arr[i][k-1] == '.')
            {
                adj[(i - 1) * m + k].push_back((i - 1) * m + k - 1);
                adj[(i - 1) * m + k - 1].push_back((i - 1) * m + k);
            }
                
        }
    
    if(!a ||! b)
    {
        cout<<"NO";
        return 0;
    }
    distance [a] = 0;
    queue <int> q;
    q.push(a);
    
    while(!q.empty())
    {
        int c = q.front();
        q.pop();
      
        for(auto u : adj[c])
        {
            if(processed[u])
                {
                    continue;
                }
            processed[u] = true;
            distance[u] = distance [c] + 1;
            parent [u] = c;
            q.push(u);
            if(u == b)
            {
                break;
            }
        }
    }
    
    
    if(distance [b]!= 0)
    {
        cout<<"YES"<<"\n";
    }
    else
    {
        cout <<"NO";
        return 0;
    }
    
    int value = 0;
    
    
    
    char *path = new char [n * m + 1];
    int i = n * m;
    
    while (b != a)
    {
        value = b - parent[b];
        if(value == 1)
        {
            path[i] = 'R';
            i --;
        }
        else if (value == -1)
        {
            path[i] = 'L';
            i --;
        }
        else if (value == m)
        {
            path[i] = 'D';
            i --;
            
        }
        else
        {
            path[i] = 'U';
            i --;
        }
        b = parent[b];
    }
    cout<<n * m - i<<"\n";
    i++;
    while(i<= n*m)
    {
        cout<<path[i];
        i++;
    }
    
 
    return 0;
}
