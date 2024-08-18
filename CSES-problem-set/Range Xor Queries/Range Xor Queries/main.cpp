//
//  main.cpp
//  Range Xor Queries
//
//  Created by Yousef on 02.03.20.
//  Copyright © 2020 Yousef. All rights reserved.
//
 
#include <iostream>
#include <math.h>
using namespace std;
 
 
long long sum (long long *tree, int size, int a, int b)
{
    a += size - 1;
    b += size -1;
    long long sum = 0;
    while (a<=b)
    {
        if((a & 1) ==1)
        {
            sum ^= tree[a++];
        }
        if((b & 1) == 0 )
        {
            sum ^= tree[b--];
        }
        a/= 2;
        b/= 2;
    }
    return sum;
}
 
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, q;
    
    cin>>n>>q;
    
    long long *arr = new long long [n];
  
    for(int i = 0; i < n; i++)
    {
        cin>> arr[i];
    }
    
    int size = log2(n);
    int length;
    
    if((2<<size)/2 == n)
    {
         length = 2 * n;
    }
    else
    {
        length = 2 * (2<<size) + 1;
    }
    
    long long * tree = new long long [length]{0};
    
    for(int i=0; i<n; i++)
    {
        tree[n + i] = arr[i];
    }
    for(int i = n - 1; i>0; i--)
    {
        tree[i] =  tree[2 * i] ^ tree[2 * i + 1];
    }
    long long a, b;
    
    for(int k = 0; k< q; k++)
    {
        cin>>a>>b;
        cout<<sum(tree, n, a, b)<<"\n";
    
    }
    
    return 0;
}
