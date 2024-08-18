//
//  main.cpp
//  Range Minimum Queries I
//
//  Created by Yousef on 28.02.20.
//  Copyright © 2020 Yousef. All rights reserved.
//
 
#include <iostream>
#include <math.h>
using namespace std;
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, a, b;
    cin>>n>>q;
    int size= (int)log2(n);
    
    long long * arr = new long long [n];
    
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    long long ** sparse = new long long *[n];
    
    for(int i=0; i< n; i++)
    {
        sparse[i] = new long long [size];
        sparse[i][0] = arr[i];
    }
    
    
    for(int k = 1 ; (2<<k)/2 <= n; k++)
    {
        for(int i = 0; i + (2<<k)/2 - 1 < n; i++)
        {
            sparse[i][k] = min (sparse[i][k-1], sparse[((2<<k)/ 4) + i][k-1]);
           
        }
    }
    
    for(int i = 0; i < q; i++)
    {
        cin>>a>>b;
        a -= 1;
        b -= 1;
        int k = b - a + 1;
        int l = (int)log2(k);
        
        cout<< min(sparse[a][l], sparse[a + k - (2<<l)/2][l])<<"\n";
       
    }
    
    return 0;
}
