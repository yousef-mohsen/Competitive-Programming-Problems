
 //
//  main.cpp
//  Traffic Lights
//
//  Created by Yousef on 24.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <algorithm>
# include <set>
#include <iterator>
using namespace std;


int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(0); cin.tie(0);

    long long x, p, value, tmp_1, tmp_2;
    multiset <long long> s;
    multiset < long long > d;
    int n;
    cin>>x>>n>>p;
    
    s.insert(0LL);
    s.insert(x);
    
    d.insert(0);
    d.insert(x-p);
    d.insert(p);
    
    auto it = d.end();
    advance(it,-1);
    cout<<*(it)<<" ";
    s.insert(p);
    
    for(int i =1; i<n; i++)
    {
        cin>> value;
        auto it_2 = s.upper_bound(value);
        tmp_2 = *it_2;
        tmp_1 = *(--it_2);
        d.erase(d.find(tmp_2 - tmp_1));
        d.insert(value - tmp_1);
        d.insert(tmp_2 - value);
        auto it_3 = d.end();
        advance(it_3,-1);
        cout<<*it_3<<" ";
        s.insert(value);
        
    }
  
    return 0;
}

