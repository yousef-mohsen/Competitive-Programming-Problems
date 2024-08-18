//
//  main.cpp
//  Sliding Median
//
//  Created by Yousef on 28.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//
 
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
 
//#include <bits/stdc++.h>
using namespace std;
 
 
int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n,k;
    cin>>n>>k;
    long long * arr = new long long[n];
 
    vector <long long > v;
    
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        
        v.push_back(arr[i]);
        
        if(v.size() == k)
        {
            sort (v.begin(), v.end());
            auto it = v.begin();
            if(k % 2 ==0 )
            {
             // advance(it, k/2 -1);
            }
            else
            {
           // advance(it, k/2);
            }
            //cout<<*it<<" ";
            v.erase(find(v.begin(), v.end(),arr[i - k + 1]));
        }
        
        
    }
 
    return 0;
}
