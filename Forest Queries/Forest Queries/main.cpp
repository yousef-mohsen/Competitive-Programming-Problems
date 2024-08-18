//
//  main.cpp
//  Forest Queries
//
//  Created by Yousef on 19.09.20.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, x1, x2, y1, y2, sum;
    char c;
    cin>>n>>q;
    vector<vector<int>> v (n + 1, vector<int>(n + 1));
    for(int i = 0; i <= n; i++)
    {
        v[0][i] = 0;
        v[i][0] = 0;
    }
    for(int i = 1; i<=n; i++)
    {
        sum = 0;
        for(int k = 1; k <= n; k++)
        {
            
            cin>>c;
            if(c == '*')
            {
                sum ++;
            }
            v[i][k] = v[i- 1][k] + sum;
            
        }
    }
    
    while(q--)
    {
        cin>>y1>>x1>>y2>>x2;
        sum = v[y2][x2];
        sum -= v[y2][x1 - 1];
        sum -= v[y1 - 1][x2];
        sum+= v[y1 - 1][x1 - 1];
        cout<<sum<<"\n";
        
    }
    
    return 0;
}
