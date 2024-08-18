//
//  main.cpp
//  Dice Combinations
//
//  Created by Yousef on 06.01.20.
//  Copyright © 2020 Yousef. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    long long * arr = new long long [n+1];
    arr[0] = 1;
    long long mod = 1000000007;
    
    for(int i=1; i<=n; i++)
    {
        arr[i] = 0;
        for(int c = 1; c<=6; c++)
        {
            if(i-c >=0)
            {
                arr[i] += arr[i - c];
            }
           
        }
         arr[i] = arr[i] % mod;
    }
    cout<< arr[n];
    return 0;
}
