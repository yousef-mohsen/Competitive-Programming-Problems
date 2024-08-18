//
//  main.cpp
//  Edit Distance
//
//  Created by Yousef on 26.04.20.
//
 
#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(0); cin.tie(0);
    string n, m;
    cin>>n;
    cin>>m;
    
    int a = n.length();
    int b = m.length();
    
    
    vector<vector<long long>> dist (b + 1, vector<long long>(a + 1));
    
    for(int i = 0; i <= a; i++)
    {
        dist[0][i] = i;
    }
    
    for(int i = 0; i <= b; i++)
       {
           dist[i][0] = i;
       }

    for(int i = 1; i <= b; i++)
        for(int k = 1; k <= a; k++)
            {
                
                dist[i][k] = min(min(dist[i - 1][k] + 1, dist [i][k - 1] + 1),dist[i - 1][k - 1] + (n[k - 1] != m[i - 1]));
            }
    cout<<dist[b][a];
    
    return 0;
}
