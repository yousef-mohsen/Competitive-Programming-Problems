//
//  main.cpp
//  Towers
//
//  Created by Yousef on 22.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//
 
#include <iostream>
#include <set>
using namespace std;
 
 
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    multiset <long long> s;
    long long value;
    int counter = 0;
    
    for(int i=0; i<n; i++)
    {
        cin>>value;
        auto v = s.upper_bound(value);
        
        if(v == s.end())
        {
            counter ++;
            s.insert(value);
        }
        else
        {
            s.erase(s.find(*v));
            s.insert(value);
        }
        
    cout<<counter;
    return 0;
}
