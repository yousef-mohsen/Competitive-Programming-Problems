//
//  main.cpp
//  Stick Lengths
//
//  Created by Yousef on 22.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    vector<int> v;
    long long sum, m;
    for(int i=0; i<n; i++)
    {
        cin>>m;
        v.push_back(m);
        sum += m;
    }
    
    sort(v.begin(), v.end());
    int value = (v.end() - v.begin())/2;
    value = v[value];
    long long counter = 0;
    
    for(auto m:v)
    {
        counter += abs(m - value);
        
    }
    
    cout<<counter;
    
    
    return 0;
}
