//
//  main.cpp
//  String Matching
//
//  Created by Yousef on 22.10.20.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s, p;
    cin>>s>>p;
    long long a = 911382323, b = 972663749, hp, ans = 0, v;
    vector<long long >h (s.size());
    vector<long long> po (s.size());
    h[0] = s[0] - 'a';
    hp = p[0] - 'a';
    po[0] = 1;
    
    for(int i = 1; i < s.size(); i++)
    {
        h[i] = (h[i - 1] * a) + s[i] - 'a';
        if(h[i] >= b)
            h[i] %= b;
        if(i < p.size())
        {
            hp = (hp * a) + p[i] - 'a';
                if(hp >= b)
                    hp %= b;
        }
        po[i] = po[i - 1] * a;
        po[i] = po[i] >= b ? po[i] % b: po[i];
            
    }
    
    for(int i = p.size() - 1; i< s.size(); i++)
    {
        
        if(i == p.size() - 1)
            v = h[i];
        else
        {
            v = (h[i] - h[i - p.size()] * po[p.size()]) % b;
        }
        if(v < 0)
            v += b;
        if(v == hp && s[i] == p[p.size() - 1] && s[i - p.size() + 1] == p[0])
        {
            ans ++;
        }
    }
    cout<<ans;
    return 0;
}
