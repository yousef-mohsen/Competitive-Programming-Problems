//
//  main.cpp
//  Problem B - Cinema Cashier
//
//  Created by Yousef on 09.08.20.
//

# include <iostream>
# include <math.h>
# include <vector>
# include <tuple>
#include <stdlib.h>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    double n, k, x, y, w;
    cin>>n>>k;
    double max = 1e8;
    
    x = ceil(k/2);
    y = x;
    vector<vector<double>> d(k+1, vector<double>(k+1, 0));
    vector<vector<bool>> v(k+1, vector<bool>(k+1, 0));
    
    for(int i = 1; i <= k; i++)
    {
        for(int q = 1; q <= k; q++)
        {
            d[i][q]= d[i][q - 1]+ fabs(x - q)+ fabs(y - i);
        }
    }
    int m = k;
   
    while(n--)
    {
        cin>>w;
        tuple <double, double, double, double> t;
        t = make_tuple(max,max,max,max);
        
        for(int i = 1; i<= k; i++)
        {
            for (int c = 1; c <= k - w + 1; c++)
            {
                bool f = true;
                for(int q = c; q < c + w; q++)
                {
                    if(v[i][q])
                    {
                        f = false;
                        break;
                    }
                }
                if(f)
                {
                    tuple <double, double, double, double> r;
                    
                    r = make_tuple(d[i][c+w-1] - d[i][c-1] ,i,c,c + w -1);
                    if(r<t)
                    {
                        t = r; ////
                    }
                }
            }
        }
        if(get<0>(t)!= max)
        {
            for(int z = get<2>(t); z <= get<3>(t); z++)
            {
                v[get<1>(t)][z] = true;
            }
            
            cout <<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t)<<"\n";
        }
        else
        {
            cout<<-1<<"\n";
        }
        
        
        
    }
    
    
    
    return 0;
}
