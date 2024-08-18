//
//  main.cpp
//  Coin Combinations I
//
//  Created by Yousef on 07.01.20.
//  Copyright © 2020 Yousef. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stack>


using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x;
    cin>>n>>x;
    long long mo = 1e9 + 7;
    long long * coins = new long long [n];
    stack<long long> s;
    
    for(int i = 0; i < n; i++)
    {
        cin>>coins[i];
        
    }
    
    long long * value = new long long [x+1]{0};
 
    value[0] = 1;
    int q =0;
    while (q!=n)
    {
        for(long long i = coins[q]; i <=x; i++)
        {
            value [i] += value [i - coins[q]];
            if(value[i] > mo)
            {
              value [i] -=mo;
            }
            
        }
        q++;
        
    }
    
    cout<<value[x];
    return 0;
}
