//
//  main.cpp
//  Range Sum Queries I
//
//  Created by Yousef on 28.02.20.
//  Copyright © 2020 Yousef. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    
    int n, q, a, b;
    cin>>n>>q;
    
    long long * arr = new long long [n+1];
    
    arr[0] = 0;
    
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
        arr[i]+= arr[i-1];
    }
    
    for(int i=0; i<q; i++)
    {
        cin>>a>>b;
        cout<<arr[b] - arr [a-1]<<"\n";
    }
    
    return 0;
}
