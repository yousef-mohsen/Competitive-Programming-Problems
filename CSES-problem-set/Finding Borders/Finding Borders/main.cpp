//
//  main.cpp
//  Finding Borders
//
//  Created by Yousef on 23.10.20.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    long long a = 911382323, b = 972663749, ans = 0;
    cin>>s;
    vector <long long> h(s.size());
    vector<long long> po (s.size());
    h[0] = s[0] - 'a';
    po[0] = 1;
    int t = s.size();
    
    for(int i = 1; i < t; i++)
    {
        h[i] = h[i - 1] * a + s[i] - 'a';
        h[i] = h[i] >= b ? h[i] % b : h[i];
        po[i] = a * po[i - 1];
        po[i] = po[i] >= b ? po[i] % b : po[i];
    }
    
    
    for(int i = 0; i < t - 1; i ++)
    {
        long long v = h[t - 1] - (h[t - 2 - i]) * po[i + 1];
        v %= b;
        v = v < 0 ? v + b : v;
        
        if(h[i] == v && s[0] == s[t - 1 - i] && s[i] == s[t - 1])
            cout<<i + 1<<" ";
    }
    
    return 0;
}
