//
//  main.cpp
//  Blindfolded Bullseye
//
//  Created by Yousef on 05.04.21.
//

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <math.h>

typedef long long ll;
using namespace std;

ll binr (ll y, ll irr, ll mode)
{
    string s;
    for(ll i = 32; i >= 0; i--)
    {
        if(y + ((1LL)<<i) > 1e9)
            continue;
        if(mode)
            cout<<irr<<" "<<y + (1<<i)<<endl;
        else
            cout<<y + (1<<i)<<" "<<irr<<endl;
        cin>>s;
        if(s == "CENTER")
            return (1e15);
        if(s == "HIT")
            y +=  (1<<i);
        
    }
    return y;
}

ll binl (ll y, ll irr, ll mode)
{
    string s;
    for(ll i = 32; i >= 0; i--)
    {
        if(y - ((1LL)<<i) < -1e9)
            continue;
        if(mode)
            cout<<irr<<" "<<y - (1<<i)<<endl;
        else
            cout<<y - (1<<i)<<" "<<irr<<endl;
        cin>>s;
        if(s == "CENTER")
            return (1e15);
        if(s == "HIT")
            y -=  (1<<i);
        
    }
    return y;
}
     
int main(int argc, const char * argv[]) {
    ll t, a, b;
    string s;
    vector<ll> x;
    vector<pair<ll,ll>> p;
    x.push_back(-1 * (5e8));
    x.push_back(5e8);
    x.push_back(75e7);
    x.push_back(-75e7);
    x.push_back(1e9);
    x.push_back(-1e9);
    x.push_back(0);
    for(auto a: x)
        for(auto t: x)
            if(!(llabs(a)== llabs(t) &&  llabs(a) == 1e9))
            p.push_back({a,t});
    
    
    cin>>t>>a>>b;
    
    for(int i = 1; i <= t; i++)
    {
        
        for(auto a: p)
        {
                cout<<a.first<<" "<<a.second<<endl;
                cin>>s;
                
                if(s == "CENTER")
                {
                    break;
                }
                if(s == "HIT")
                {
                    ll left, right, up, down;
                    if(a.first ==  -1e9)
                        left = -1e9;
                    else
                    {
                        left =
                        binl(a.first, a.second, 0);
                        if(left == 1e15)
                            break;
                    }
                    if(a.first == 1e9 )
                    {
                        right = 1e9;
                    }
                    else
                    {
                        right =
                        binr(a.first, a.second, 0);
                        if(right == 1e15)
                            break;
                    }
               
                    
                    if(a.second ==  -1e9)
                        down = -1e9;
                    else
                    {
                        down =
                        binl(a.second, (left + right) / 2 , 1);
                        if(down == 1e15)
                            break;
                    }
                    if(a.second == 1e9 )
                    {
                        up = 1e9;
                    }
                    else
                    {
                        up =
                        binr(a.second , (left + right) / 2, 1);
                        if(up == 1e15)
                            break;
                    }
                    
                    cout<<((left + right) /2)<<" "<<((up+down)/2) <<endl;
                    cin>>s;
                   
                    break;
                    
                }
               
            }
    }
    return 0;
}
