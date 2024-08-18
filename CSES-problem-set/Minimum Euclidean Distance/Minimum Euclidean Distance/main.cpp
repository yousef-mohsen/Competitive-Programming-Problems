//
//  main.cpp
//  Minimum Euclidean Distance
//
//  Created by Yousef on 22.03.21.
//
 
#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <set>
#include<algorithm>
#include <stdlib.h>
#include <fstream>
#include <climits>
 
typedef long long ll;
using namespace std;
 
ll euc (ll x1, ll y1, ll x2, ll y2)
{
    ll ans1 = x1 - x2;
    ll ans2 = y1 - y2;
    return ans1 * ans1 + ans2 * ans2;
}
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    ll n, x, y, d = 8e18, begin = 1;
    set<pair<ll, ll>> ly;
    
    cin>>n;
    vector<pair<ll,ll>> lx(n);
    for(int i = 0; i < n; i++)
    {
        cin>>x>>y;
        lx[i] = {x, y};
    }
    sort(lx.begin(), lx.end());
    
    ly.insert({lx[0].second, lx[0].first});
    pair<ll, ll> c;
    
    
    for(int i = 1; i < n; i ++)
    {
        c = {lx[i].first, lx[i].second};
        
        while(c.first - d > lx[begin].first)
        {
            ly.erase({(lx[begin]).second, (lx[begin]).first});
            begin++;
        }
 
        auto in = make_pair(c.second, c.first);
        ly.insert(in);
        int counter = 0;
        auto it = ly.find(in);
        auto temp = ly.end();
        temp --;
        while(counter < 9)
        {
            auto v = euc((*it).second, (*it).first, c.first, c.second);
            if(d > v && v != 0)
                d = v;
            
            if(it!= temp)
            it++;
            else
                break;
            counter ++;
        }
        
        it = ly.find(in);
        counter = 0;
        while(counter < 9)
        {
            auto v = euc((*it).second, (*it).first, c.first, c.second);
            if(d > v && v != 0)
                d = v;
            if(it!= ly.begin())
            it--;
            else
                break;
            counter ++;
        }

    }
    cout<<d;
    return 0;
}
