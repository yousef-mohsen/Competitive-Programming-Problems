//
//  main.cpp
//  Exponentiation II
//
//  Created by Yousef on 15.03.20.
//
 


 
long long modpow (long long base, long long power, long long mo)
{
    if(power == 0)
        return 1;
    long long value = modpow(base, power / 2, mo);
    value *= value;
    if(value >= mo)
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
    long long base, power, c;
    
    cin>>n;
    
    for(int i = 0; i < n; i++)
    {
        cin>>base>>power>>c;
        long long value = modpow(power, c, 1e9 + 6);
        cout<< modpow(base, value, 1e9 + 7)<<"\n";
        
    }
    return 0;
}
