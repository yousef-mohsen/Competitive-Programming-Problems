//
//  main.cpp
//  Candy Lottery
//
//  Created by Yousef on 15.10.20.
//
 
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    double n, k;
    cin>>n>>k;
    
    vector<vector<double>> v(n + 1, vector<double> (k + 1));
    vector<vector<double>> v2(n + 1, vector<double> (k + 1));
    double c = 1.0 / k;
    v[1][1] = c;
    v2[1][1] = c;
    int t = fmax(k, n);
    for(int i = 2; i <= t ; i++)
    {
        if(i<= n)
        {
            v[i][1] = v[i - 1][1] * c;
            v2[i][1] = v[i][1];
        
        }
        if(i<=k)
        {
            v[1][i] = c;
            v2[1][i] = v2[1][i - 1] + v[1][i - 1];
        }
        
    }
    
    for(int i = 2; i <= n; i++)
    {
        
        for(int q = 2; q <= k; q++)
        {
            v[i][q] = c * v2[i - 1][q - 1];
            v[i][q] += c * q * v[i - 1][q];
            v2[i][q] = v[i][q] + v2[i][q - 1];
        }
    }
    double sum = 0;
    for(int i = 1; i <= k; i++)
    {
        sum += double(i) * v[n][i];
    }
 
    printf("%.6f\n", sum);
    return 0;
}
