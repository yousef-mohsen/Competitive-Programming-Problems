//
//  main.cpp
//  Company Queries I
//
//  Created by Yousef on 25.09.20.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, t, c = 1 ,tt = 0, x, k;
    cin>>n>>q;
    t = n;
    
    while(t)
    {
        if(t & 1)
            tt = c;
        c++;
        t = t>>1;
    }
    
    vector<vector<int>> v (tt + 1, vector<int>(n + 1));
    v[1][1] = 0;
    for(int i = 2; i <= n; i++)
    {
        cin>>v[1][i];
    }
    
    for(int i = 2; i <= tt; i++)
    {
        for(int k = 1; k <=n; k++)
            v[i][k] = v[i - 1][v[i - 1][k]];
    }
    
    for(int i = 1; i <= q; i++)
    {
        cin>>x>>k;
        bool f = true;
        c = 0;
        for(int z = 18; z>=0; z--)
        {
            if(k & (1<<z))
            {
                x = v[z + 1][x];
                if(x== 0)
                {
                    cout<<-1<<" ";
                    f = false;
                    break;
                }
            }
        }
        if(f)
            cout<<x<<" ";
    }
    
    return 0;
}
