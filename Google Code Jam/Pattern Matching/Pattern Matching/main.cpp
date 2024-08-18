//
//  main.cpp
//  Pattern Matching
//
//  Created by Yousef on 31.03.21.
//

#include <iostream>
#include <vector>
#include <string>

typedef long long ll;
using namespace std;
ll m_s = 0, m_p = 0, n, t;

vector<string> v;
vector<string> pre;
vector<string> suff;

void ans(ll c)
{
    
    m_s = 1, m_p = 1;
    pre = vector<string> (n + 1);
    suff = vector<string> (n + 1);
    
    for(int i = 1; i <= n; i++)
    {
        while(v[i][0]!= '*')
        {
            pre[i] += v[i][0];
            v[i].erase(v[i].begin());
            
        }
        
        while(v[i][v[i].size() - 1] != '*')
        {
            suff[i] = v[i][v[i].size() - 1] + suff[i];
            v[i].pop_back();
          }
       
        if(pre[i].size() > pre[m_p].size())
            m_p = i;
        if(suff[i].size() > suff[m_s].size())
            m_s = i;
    }
    for(int i = 1; i <= n; i ++)
    {
        if(pre[m_p].find(pre[i]) != 0)
        {
            cout<<"Case #"<<c<<": "<<"*"<<"\n";
            return;
        }
        
       
        if(suff[m_s].substr(suff[m_s].size() - suff[i].size()) != (suff[i]))
        {
            
            cout<<"Case #"<<c<<": "<<"*"<<"\n";
            return;
        }
    }
    string s = pre[m_p];
    for(int i = 1; i <= n; i++)
        for(int k = 0; k < v[i].size(); k++)
        if(v[i][k] != '*')
            s+= v[i][k];
    
    s += suff[m_s];
    cout<<"Case #"<<c<<": "<<s<<"\n";
    
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>t;
    
    for(int i = 1; i <= t; i++)

    {
        cin>>n;
        v = vector<string>(n + 1);
        
        for(int k = 1; k <= n; k++)
        {
            cin>>v[k];
        }
        ans(i);
    }
    
    
    
    return 0;
}
