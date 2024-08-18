//
//  main.cpp
//  F. ucyhf
//
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int s = 1e7, d, c = 0;
    vector <bool> v (s, false);
    vector <int> p;
    cin>>d;
    for(int i = 2; i<s; i++)
    {
        if(v[i])
            continue;
        p.push_back(i);
        for(int k = i + i; k < s; k += i)
            v[k] = true;
    }
    
    for(auto n: p)
    {
        int rev = 0, num = n;
        while(num > 0)
        {
            rev = rev*10 + num %10;
            num/= 10;
        }
        if(rev!= n && !v[rev])
            c++;
        if (c == d)
        {
            cout<<n;
            return 0;
        }
    
    }
    return 0;
}
