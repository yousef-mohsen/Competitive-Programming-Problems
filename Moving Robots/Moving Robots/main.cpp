//
//  main.cpp
//  Moving Robots
//
//  Created by Yousef on 13.10.20.
//

#include <iostream>
#include <vector>
using namespace std;
typedef long long  ll;

void mul(vector<vector<double>> &a, vector<vector<double>> &b, vector<vector<double>> &c)
{
    int l = a.size(), r = b[0].size();
        
    for(int i = 1; i < l; i++)
        for(int k = 1; k < r; k++)
        {
            c[i][k] = 0;
            for(int q = 1; q < a[0].size(); q++)
            {
                c[i][k] += a[i][q] * b[q][k];
            }
        }
}

void modpow (long long power, vector<vector<double>>&x, vector<vector<double>>&f, vector<vector<double>>&g)
{
    if(power <= 1)
        return;
    modpow(power / 2, x, g, f);
    mul(f, f, g);
    
    if((power & 1) == 1)
    {
        mul(g, x, f);
        f.swap(g);
        return;
    }
    return;
}

int main(int argc, const char * argv[]) {
                                                               
    double z;
    cin>>z;
    vector<vector<double>> v(65, vector<double> (65, 0));
    vector<vector<double>> m(65, vector<double> (65, 0));
   
    
    for(int i = 2; i <= 7; i++)
    {
        for (int k = 2; k <= 7; k++)
        {
            v[(i - 1) * 8 + k  + 8][(i - 1) * 8 + k] = 1.0/ 4.0;
            v[(i - 1) * 8 + k  - 8][(i - 1) * 8 + k] = 1.0/ 4.0;
            v[(i - 1) * 8 + k + 1][(i - 1) * 8 + k] = 1.0/ 4.0;
            v[(i - 1) * 8 + k - 1][(i - 1) * 8 + k] = 1.0/ 4.0;
            }
    }
    v[7][8] = 0.5;
    v[16][8] = 0.5;
    v[2][1] = 0.5;
    v[9][1] = 0.5;
    v[49][57] = 0.5;
    v[58][57]= 0.5;
    v[56][64]= 0.5;
    v[63][64]= 0.5;
    
    for(int i = 9; i <= 49; i += 8)
    {
        v[i - 8][i] = 1.0/ 3.0;
        v[i + 8][i] = 1.0/ 3.0;
        v[i + 1][i] = 1.0/ 3.0;
    }
    for(int i = 16; i <= 56; i += 8)
       {
          v[i - 8][i] = 1.0/ 3.0;
           v[i + 8][i] = 1.0/ 3.0;
           v[i - 1][i] = 1.0/ 3.0;
       }
    for(int i = 2; i <=7; i++)
    {
        v[i + 8][i] = 1.0/3.0;
        v[i + 1][i] = 1.0 / 3.0;
        v[i - 1][i] = 1.0/ 3.0;
    }
    for(int i = 58; i <=63; i++)
     {
         v[i - 8][i] = 1.0/3.0;
         v[i + 1][i] = 1.0 / 3.0;
         v[i - 1][i] = 1.0/ 3.0;
     }
    for(int i = 1; i <= 64; i++)
    {
        m[i][i] = 1.0;
    }
    vector<vector<double>> temp(65, vector<double> (65, 0));
    vector<vector<double>> x(65, vector<double> (65, 0));
    for(int i = 1; i<=64; i++)
        for(int k = 1; k<=64; k++)
        {
            x[i][k]= v[i][k];
            temp[i][k]= v[i][k];
        }
    
    modpow (z, x, v, temp);
    mul(temp, m, v);
    double ans = 0;
        
    for(int q = 1; q <= 64; q++)
        {
            double sum = 1;
    
            for(int r = 1; r <= 64; r++)
            {
                sum*= 1.0-v[q][r];
            }
            ans+= sum;
        }
        

    printf("%.6f\n", ans);
    return 0;
}
