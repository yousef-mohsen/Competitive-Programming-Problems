//
//  main.cpp
//  B. Sheldon and Ice Pieces
//
//  Created by Yousef on 15.08.20.
//

#include <iostream>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    map<char, long long> m1,m2;
    string t, s;
    char c;
    cin>>t>>s;
    
    for(int i =0; i<t.size();i++)
    {
        if(t[i] == '9')
        {
            m1['6']+=1;
        }else if(t[i] =='5')
        {
            m1['2'] +=1;
        }
        else
        {
            m1[t[i]] +=1;
        }
    }
    
    for(int i =0; i<s.size(); i++)
    {
        
        if(s[i] == '9')
        {
            m2['6']+=1;
        }else if(s[i] == '5')
        {
            m2['2'] +=1;
        }
        else
        {
            m2[s[i]] +=1;
        }
    }
    long long mini =1e10;
    
    for(auto k:m1)
    {
        mini = min(m2[k.first]/k.second, mini);
    }
    cout<<mini;
    return 0;
}
