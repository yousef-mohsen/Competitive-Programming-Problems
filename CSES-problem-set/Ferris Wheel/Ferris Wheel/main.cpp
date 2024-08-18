//
//  main.cpp
//  Ferris Wheel
//
//  Created by Yousef on 19.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    long x;
    cin>>n>>x;
    vector <long> myVector;
    
    long long *arr = new long long [n];
  
    for(int i=0; i< n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr + n);
    int counter = 0;
    
    int lastPointer = n-1;
    int i = 0;
    while(i < lastPointer)
    {
        if(arr[i] + arr[lastPointer] <= x)
        {
            counter ++;
            i++;
            lastPointer--;
        }
        else
        {
            counter ++;
            lastPointer --;
        }
    }
  if(i==lastPointer)
      counter++;
    cout<< counter;
    return 0;
}
