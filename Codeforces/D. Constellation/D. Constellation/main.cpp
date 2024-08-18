//
//  main.cpp
//  D. Constellation
//
//  Created by y.m on 25.08.20.
//
 
#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>
using namespace std;

 
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, r, counter = 0;
    char c;
    cin>>n>>m>>r;
    vector<vector<bool>> v (n + 1 , vector<bool>(m+1, false));

    
    for (int i = 1; i <= n; i++)
        for(int k = 1; k <= m; k++)
        {
            cin>>c;
            if(c== '*')
            v[i][k] = true;
        }
    for(int z= 1; z<= min(n, m); z++)
    for (int i = 1; i <= n; i++)
        for(int k = 1; k <= m; k++)
        {
            if(!v[i][k])
                continue;
            
            int wi = min(m - k, k - 1);
            int hi = n - i;
            if(wi < 1 || hi < 2)
                continue;
            if((i + 2 * z<= n) && (k + z)<= m && (1<=k - z))
            {
                if(v[i + z][k] && v[i + 2 * z][k] && v[i+z][k+z] && v[i + z][k - z])
                {
                    counter ++;
                    if(counter == r)
                    {
                        cout<<i + z<<" "<<k<<"\n";
                        cout<<i<<" "<<k<<"\n";
                        cout<<i + 2 * z<<" "<<k<<"\n";
                        cout<<i + z<<" "<<k - z<<"\n";
                        cout<<i + z<<" "<<k + z<<"\n";
                        return 0;
                        
                    }
                
                }
            }
        }

        cout<<-1;
  
    
    return 0;
}
