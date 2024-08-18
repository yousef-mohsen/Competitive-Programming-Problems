//
//  main.cpp
//  Increasing Array
//
//  Created by Yousef on 17.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    
    long long counter = 0;
    long long  *arr = new long long [n];
    cin>>arr[0];
    for(int i=1; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]<arr[i-1])
        {
            counter += (arr[i-1]-arr[i]);
            arr[i]=arr[i-1];
        }
    }
     
    cout<<counter;
    
    
    return 0;
}
