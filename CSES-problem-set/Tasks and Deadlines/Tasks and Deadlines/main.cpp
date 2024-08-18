//
//  main.cpp
//  Tasks and Deadlines
//
//  Created by Yousef on 27.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin>>n;
    pair <long long, long long> * arr = new pair<long long, long long>[n];
    
    long long duration, deadline;
    
    for(int i=0; i<n; i++)
    {
        cin>>duration>>deadline;
        arr[i] = make_pair(duration, deadline);
    }
    
    sort(arr, arr + n);
    long long time = 0;
    long long reward = 0;
    
    for(int i =0; i<n; i++)
    {
        time += arr[i].first;
        reward += arr[i].second - time;
    }
    
    cout<<reward;
    
    return 0;
}
