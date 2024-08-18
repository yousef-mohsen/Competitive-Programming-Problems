//
//  main.cpp
//  Coin Combinations I
//
//  Created by Yousef on 07.01.20.
//  Copyright © 2020 Yousef. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin>>n>>x;
    long long mo = 1e9 + 7;
    long long * coins = new long long [n];
    
    for(int i = 0; i < n; i++)
    {
        cin>>coins[i];
    }
    
    sort (coins, coins + n);
    
    long long * value = new long long [x+1];
    value[0] = 1;
    
    for(int i = 1; i <=x; i++)
    {
        value[i] = 0;
        for(int k = 0; k < n; k++)
        {
            if(i - coins[k] <0)
            {
                break;
            }
            value [i] += value [i - coins[k]];
            
        }
        value [i] = value[i] % mo;
    }
    
    cout<<value[x];
    return 0;
}
