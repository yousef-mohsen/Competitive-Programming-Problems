//
//  main.cpp
//  Factory Machines
//
//  Created by Yousef on 27.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;


bool valid (long long time, long long arr[], int size, long long products)
{
    long long sum = 0;
    for(int i=0; i< size; i++)
    {
        sum += time / arr[i];
    }
    if(sum >= products)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    long long products;
    cin>>n>>products;
    
    long long* arr = new long long[n];
    long long min = 10000000000;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(min > arr[i])
        {
            min = arr[i];
        }
    }
    
    
    long long x = -1;
    long long z = products * min;
    
    for (long long b = z; b >= 1; b /= 2) {
        
        while (!valid(x + b, arr, n, products))
            x += b;
        
    }
    
    long long k = x+1;
    cout<<k;
    
    return 0;
}
