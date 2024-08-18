//
//  main.cpp
//  Word Combinations
//
//  Created by Yousef on 20.10.20.
//
 
#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
vector<vector<int>> t;
vector<int> v;
 
int counter = 1;
long long mo = 1e9 + 7;
 
void insert(string & s)
{
    int n = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(t[n][s[i] - 'a'] == -1)
        {
            t[n][s[i] - 'a'] = counter;
            n = counter;
            counter ++;
        }
        else
            n = t[n][s[i] - 'a'];
    }
    v[n] = 1;
}
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    //cin.exceptions(cin.failbit);
    string s, p;
    int k;
    cin>>s;
    cin>>k;
    
    t = vector<vector<int>>(1e6 + 2 , vector<int>(26, -1));
    v = vector<int>(1e6 + 2 , -1);
    vector<long long > ans(6000,0);
    for(int i = 1; i <= k; i++)
    {
        cin>>p;
        insert(p);
    }
 
    for(int i = s.size() - 1; i >= 0; i--)
    {
        k = i;
        int n = 0;
        while(k <= s.size() - 1 && t[n][s[k] - 'a']!= -1)
        {
            if(v[t[n][s[k] - 'a']] != -1)
            {
                if(k == s.size() - 1)
                    ans[i] += 1;
                else
                {
                    ans[i] += ans[k + 1];
                }
                if(ans[i] >= mo)
                    ans[i] %= mo;
            }
            n = t[n][s[k] - 'a'];
            k++;
            
        }
    }
    cout<<ans[0];
    return 0;
}
