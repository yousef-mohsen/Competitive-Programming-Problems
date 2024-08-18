//
//  main.cpp
//  Creating Strings II
//
//  Created by Yousef on 04.10.20.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
    string s;
    long long sum, counter = 1, p = mo - 2;
    cin>>s;
    sort(s.begin(), s.end());
    
    vector<long long> f (s.size() + 1);
    f[0] = 1;
    for(int i = 1; i <= s.size(); i++)
    {
        f[i] = i * f[i - 1];
        if(f[i] >= mo)
            f[i]%= mo;
    }
    sum = f[s.size()];
    
    for(int i = 1; i <= s.size(); i++)
    {
        if(s[i]== s[i - 1])
            counter ++;
        else
        {
            sum *= modpow(f[counter], p);
            if(sum > mo)
                sum %= mo;
            counter = 1;
        }
    }
    sum *=modpow(counter, p);
    cout<<sum % mo;
    
    return 0;
}
