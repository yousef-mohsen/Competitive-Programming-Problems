//
//  main.cpp
//  E. Field of Wonders
//
//  Created by Yousef on 09.08.20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, counter = 0;
    bool f;
    string s, t;
    cin>>n>>s;
    vector <string> v;
    vector <char> alpha = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    cin>>m;
    
    for(int i = 0; i < m; i++)
    {
        cin>>t;
        for(int i =0; i<s.length(); i++)
        {
            f = false;
            if (s[i] =='*')
            {
                if(s.find(t[i])!= string::npos)
                {
                    f = true;
                    break;
                }
                
            }
            else
            {
                if(s[i]!=t[i])
                {
                    f = true;
                    break;
                                
                }
            }
        }
        if(!f)
        {
        for(int i =0; i<s.length(); i++)
        {
            t.erase(remove(t.begin(), t.end(), s[i]), t.end());
        }
        v.push_back(t);
        }
    }
    
    for(auto a: alpha)
    {
        f = true;
        
        for(auto t: v)
        {
            if(t.find(a)== string::npos)
            {
                f = false;
                break;
            }
        }
        if(f)
        {
            counter ++;
        }
    }
   
    cout<<counter;
    return 0;
}
