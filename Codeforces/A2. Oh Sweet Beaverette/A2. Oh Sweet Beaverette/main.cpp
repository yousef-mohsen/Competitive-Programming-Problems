//
//  main.cpp
//  A2. Oh Sweet Beaverette
//
//  Created by Yousef on 14.08.20.
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a, b;
    long long sum = 0;
    cin>>n;
    vector<long long> v(n + 1);
    vector<long long> s(n + 1, 0);
    map <int, pair<int,int>> m;
    
    for(int i=1; i<=n;i++)
    {
        cin>>v[i];
        if(v[i]> 0)
        {
            sum+=v[i];
            
        }
        s[i] = sum;
        if(!m.count(v[i]))
        {
            m[v[i]] = make_pair(i, 0);
        }
        else
        {
            m[v[i]].second = i;}
        }
    long long max = -1e11;
    long long temp = 0;
    
    for(auto k: m)
    {
        if(k.second.second!=0)
        {
        
            temp = s[(k.second).second - 1]-s[(k.second).first];
                temp += 2*v[(k.second).second];
    
            
            if(temp > max)
            {
                a = (k.second).first;
                b = (k.second).second;
                max = temp;
            }
        }
    }
    sum = 0;
    for(int i = a+1; i<b; i++)
    {
        if(v[i]<0)
        {
            sum+=1;
        }
    }
    cout<<max<<" "<<n-(b-a+1) + sum<<"\n";
    for(int i = 1; i<a;i++)
    {
        cout<<i<<" ";
    }
    for(int i = a+1; i<b;i++)
    {
        if(v[i]<0)
            cout<<i<<" ";
    }
    for(int i = b + 1; i<=n;i++)
    {
        cout<<i<<" ";
    }
    
    return 0;
}
