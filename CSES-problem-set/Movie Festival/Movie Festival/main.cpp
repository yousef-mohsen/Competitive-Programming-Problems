//
//  main.cpp
//  Movie Festival
//
//  Created by Yousef on 20.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
   
    int n;
    cin>>n;
    
    pair<long long,long long> * arr = new pair<long long,long long> [n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].second;
        cin>>arr[i].first;
    }
    sort(arr, arr+n);
    int counter = 1;
    int pos = 0;
    for(int i=0; i<n-1;i++)
    {
        if(arr[pos].first<=arr[i+1].second)
        {
            
                counter +=1;
                pos = i+1;
            
        }
    }
    cout<< counter;
    return 0;
}
