//
//  main.cpp
//  Shortest Routes II
//
//  Created by Yousef on 12.03.20.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, q, a, b;
    long long c;
    long long inf = 1e12;
    
    cin>>n>>m>>q;
    vector<vector<long long>> mat (n + 1, vector<long long>(n + 1, inf));
    
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        mat[a][b] = min (mat[a][b],c);
        mat[b][a] = min (mat[b][a],c);
    }

    for(int i = 1; i <= n; i++)
    {
        mat[i][i] = 0;
    }
    

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
    
    for(int i = 0; i < q; i++)
    {
        cin>>a>>b;
        if(mat[a][b] == inf)
        {
            cout<<-1<<"\n";
        }
        else
        {
            cout<<mat[a][b]<<"\n";
        }
    }
    
    return 0;
}
