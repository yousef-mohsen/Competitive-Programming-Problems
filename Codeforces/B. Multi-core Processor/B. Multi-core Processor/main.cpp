//
//  main.cpp
//  B. Multi-core Processor
//
//  Created by Yousef on 17.08.20.
//

#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin>>n>>m>>k;
    
    vector<vector<int>> v (n + 1,vector<int>(m + 1));
    vector<int> cores(n + 1,0);
    vector<vector<int>> f (k + 1,vector<int>());
    vector<int> cells(k + 1, 0);
    
    for(int i = 1; i <= n; i++)
        for(int z = 1;  z<= m; z++)
        {
            cin>>v[i][z];
        }
    
    for(int i = 1; i <= m; i++)
    {
        for(int z = 1; z <= n; z++)
        {
            if(v[z][i])
            {
                if(cells[v[z][i]])
                {
                    if(!cores[z])
                    {
                        cores[z] = i;
                    }
                    
                }
                if(!cores[z])
                    f[v[z][i]].push_back(z);
            }
        }
        
        for(int b = 1;b<=k;b++)
        {
            if(f[b].size() > 1)
                {
                    cells[b] = 1;
                    for(int y= 0; y<f[b].size();y++)
                    {
                        if(!cores[f[b][y]])
                            cores[f[b][y]] = i;
                    }
                    f[b] = vector<int>();
                }
            else
                {
                    f[b] = vector<int>();
                }
        }
        
    }
    
    for(int i = 1; i<=n; i++)
    {
        cout<<cores[i]<<"\n";
    }
    
    return 0;
}
