//
//  main.cpp
//  Dice Probability
//
//  Created by Yousef on 10.10.20.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a, b, l;
    double sum = 0;
    cin>>n>>a>>b;
    l = n * 6 + 1;
    vector<vector<double>> v(n + 1 , vector<double>(l, 0) );
    v[1][1]= 1.0/6.0;
    v[1][2]= 1.0/6.0;
    v[1][3]= 1.0/6.0;
    v[1][4]= 1.0/6.0;
    v[1][5]= 1.0/6.0;
    v[1][6]= 1.0/6.0;
    
    for(int i = 2; i <= n; i++)
        for(int k = i; k < l; k++)
        {
            for(int q = 1; q <=6; q++)
            {
                if(k - q < 1)
                    break;
                v[i][k] += (1.0 / 6.0) * v[i - 1][k - q];
            }
        }
    
    for(; a<=b; a++)
        sum += v[n][a];

    printf("%.6f", sum);
    
    return 0;
}
