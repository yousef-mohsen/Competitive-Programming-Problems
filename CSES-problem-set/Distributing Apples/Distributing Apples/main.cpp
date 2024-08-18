//
//  main.cpp
//  Distributing Apples
//
//  Created by Yousef on 05.10.20.
//

#include <iostream>
#include <vector>

using namespace std;
long long mo = 1e9 + 7;

long long modpow (long long base, long long power)
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

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n, m, sum;
    cin>>n>>m;
    vector<long long> f(n + m);
    f[0] = 1;
    
    for(long long i = 1; i < n + m; i++)
    {
        f[i] = f[i - 1] * i;
        if(f[i] > mo)
            f[i] %= mo;
    }
    sum = f[n + m - 1];
    
    sum *= modpow(f[m], mo - 2);
    sum %= mo;
    sum *= modpow(f[n - 1], mo - 2);
    
    cout<<sum % mo;

    return 0;
}
