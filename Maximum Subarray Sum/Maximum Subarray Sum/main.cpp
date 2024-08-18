//
//  main.cpp
//  Maximum Subarray Sum
//
//  Created by Yousef on 20.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    
    long long * arr = new long long [n];
     for(int i=0;i<n;i++)
         cin>>arr[i];
    
    long long best = arr[0];
    long long maximum  = arr[0];
    
    
    for(int i=0;i<n-1;i++)
    {
        if(best<1)
        {best = arr[i+1];}
            else
            {best+= arr[i+1];}
        
        maximum =max(maximum,best);
    }
    cout<<maximum;
    return 0;
}
