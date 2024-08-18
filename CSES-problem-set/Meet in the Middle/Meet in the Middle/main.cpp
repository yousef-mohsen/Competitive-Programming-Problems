//
//  main.cpp
//  Meet in the Middle
//
//  Created by Yousef on 03.01.21.
//
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, x, t, v;
    
    cin>>n>>x;
    t = n / 2;
    vector<ll> v1;
    vector<ll> v2;
    vector<ll> v11;
    vector<ll> v22;
    for(int i = 1; i <= n; i++)
    {
        cin>>v;
        if (i <= t)
        {
            v1.push_back(v);
        }
        else
        {
            v2.push_back(v);
        }
    }
    v11.push_back(0);
    for(int i = 0; i < t; i++)
    {
        ll si = v11.size();
        for(int k = 0; k < si; k++)
        {
            if(v11[k] + v1[i] <= x)
            v11.push_back(v11[k] + v1[i]);
        }
    }
    v22.push_back(0);
    for(int i = 0; i < n - t; i++)
    {
        ll si = v22.size();
        for(int k = 0; k < si; k++)
        {
            if(v22[k] + v2[i] <= x)
            v22.push_back(v22[k] + v2[i]);
        }
    }
    sort(v11.begin(), v11.end());
    sort(v22.begin(), v22.end());
    
    ll s1 = v11.size();
    ll s2 = v22.size();
    ll p1 = 0;
    ll p2 = s2 - 1;
    ll ans = 0;
    while(p1 < s1 && p2 >= 0)
    {
        if(v11[p1] + v22[p2] == x)
        {
            ll c1 = 0;
            ll c2 = 0;
            ll temp = v11[p1];
            do{
                c1++;
                p1++;
            }while(p1 != s1 && temp  == v11[p1]);
            
            
            temp = v22[p2];
            do{
                c2++;
                p2--;
            }while(p2 > 0 && temp  == v22[p2]);
            ans+= c1*c2;
            
        }
        else if(v11[p1] + v22[p2] < x)
        {
            p1++;
        }
        else
        {
            p2--;
        }
        
        
    }
    cout<<ans;
    return 0;
}
