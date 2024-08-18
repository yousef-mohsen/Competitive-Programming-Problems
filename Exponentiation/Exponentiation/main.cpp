//
//  main.cpp
//  Exponentiation
//
//  Created by Yousef on 09.03.20.
//  Copyright © 2020 Yousef. All rights reserved.
//
long long mo = 1e9 + 7;

long long modpow (long long base, long long power )
{
    if(power == 0)
        return 1;
    long long value = modpow(base, power / 2);
    value *= value;
    if(value > mo)
    {
        value %= mo;
    }
    if((power & 1) == 1)
        return (value * base) % mo;
    return value;
}

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    long long base, power;
    
    cin>>n;
    
    for(int i = 0; i < n; i++)
    {
        cin>>base>>power;
        cout<<modpow(base, power)<<"\n";
        
    }
    return 0;
}
