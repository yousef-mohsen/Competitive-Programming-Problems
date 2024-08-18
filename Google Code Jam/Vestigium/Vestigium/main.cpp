//
//  main.cpp
//  Vestigium
//
//  Created by Yousef on 24.03.21.
//

#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, n, m, trace, r, c;
    cin>>t;
    
    for (int i = 1; i <= t; i++)
    {
        cin>>n;
        trace = 0, r = 0, c = 0;
        
        vector<vector<bool>>  raws(101, vector<bool>(101, false));
        vector<vector<bool>> columns(101, vector<bool>(101, false)) ;
        
        
        
        vector<bool>r_t(101, false);
        vector<bool>c_t(101, false);
        
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                cin>>m;
                if(j == k)
                    trace+= m;
                
                if(raws[j][m])
                {
                    if(!r_t[j])
                    {
                        r++;
                        r_t[j] = 1;
                    }
                }
                else
                {
                    raws[j][m] = 1;
                }
                
                if(columns[k][m])
                {
                    if(!c_t[k])
                    {
                        c++;
                        c_t[k] = 1;
                    }
                }
                else
                {
                    columns[k][m] = 1;
                }
                
            }
        }
        cout<<"Case #"<<i<<": "<<trace<<" "<<r<<" "<<c<<"\n";
    }
    return 0;
}
