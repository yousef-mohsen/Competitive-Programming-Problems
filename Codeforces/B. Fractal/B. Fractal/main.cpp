//
//  main.cpp
//  B. Fractal
//
//  Created by y.m on 19.08.20.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, k;
    
    cin>>n>>k;
    vector<vector<char>>v (n + 1, vector<char>(n+1));
    vector<vector<char>>v1;
    for(int i = 1; i <= n; i++)
        for(int k = 1; k <= n; k++)
        {
            cin>>v[i][k];
        }
    
    for(int i = 1; i < k; i++)
    {
        v1 = vector<vector<char>> (pow(n, i + 1) + 1, vector<char>(pow(n, i + 1) + 1,'.'));
        
        int value = pow(n, i + 1);
        int value2 = pow(n, i);
        
        for(int q = 1; q <= value; q++)
            for(int w = 1; w <= value; w++)
            {
                v1[q][w]= v[ceil(q/float(n))][ceil(w/float(n))];
                    
            }

        for (int z = 1; z < value; z += value2)
            for(int q = 1; q < value; q += value2)
                for(int k = 1; k <= value2;k++)
                    for(int n = 1; n <= value2; n++)
                    {
                        if(v[k][n]!='.')
                            v1[z + k - 1][ q + n - 1] = v[k][n];
                    }
        v=v1;
    }
    
    int temp =pow(n,k);
    for(int i= 1; i<= temp;i++)
    {
        for(int q= 1; q<= temp; q++)
        {
            if(k==1)
            {
                cout<<v[i][q];
            }
            else
            {
                cout<<v1[i][q];
            }
        }
        cout<<"\n";
    }
    
    return 0;
}
