//
//  main.cpp
//  Sum of Divisors
//
//  Created by Yousef on 02.10.20.
//
 
#include <iostream>
#include <math.h>
 
using namespace std;
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n , sum = 0, s, mo = 1e9 + 7, t;
    cin>>n;
    s = sqrt(n);

    for(long long  i = 1; i <= s; i++)
    {
        t = n / i;
        sum += ((t - i + 1)%mo) * (i%mo);
        sum %= mo;
        sum += ((((t - i) % mo) * ((i+1 + t) % mo) % mo) * 500000004) % mo;
        
    }
    cout<<sum % mo;
    
    
    return 0;
}
