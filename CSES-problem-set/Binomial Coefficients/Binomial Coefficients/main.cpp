//
//  main.cpp
//  Binomial Coefficients
//
//  Created by Yousef on 04.10.20.
//

#include <iostream>
#include <vector>
using namespace std;
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

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n, c = 1, m = - 1;
    cin>>n;
    vector<long long> q (2 * n + 1);
    n = 2 * n;
    
    for(int i = 1; i <= n; i++)
    {
        cin>>q[c];
        m = max(m, q[c]);
        c++;
    }
    vector<long long > f (m + 1);
    f[0] = 1;
    
    for(int i = 1; i <=m; i++)
    {
        f[i]= f[i - 1] * i;
        if(f[i] > mo)
            f[i] %= mo;
    }
    long long p = mo - 2;
    
    for(int i = 1; i <=n; i+= 2)
    {
        cout<<(
               (
                (f[q[i]] * modpow(f[q[i + 1]], p))% mo)
               *
        modpow(f[q[i] - q[i + 1]], p)) % mo<<"\n";
    }
    
    return 0;
}
