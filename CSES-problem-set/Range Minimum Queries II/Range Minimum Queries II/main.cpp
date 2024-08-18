//
//  main.cpp
//  Range Minimum Queries II
//
//  Created by Yousef on 02.03.20.
//  Copyright © 2020 Yousef. All rights reserved.
//
 
#include <iostream>
#include <math.h>
using namespace std;
 
void update(long long * tree,int size, int position,long long value)
{
    position += size - 1;
    tree[position] = value;
    for(position/=2; position>=1 ; position/=2)
    {
        tree[position] = min(tree[2 * position], tree[2 * position +1]);
    }
}
 
long long mini (long long *tree, int size, int a, int b)
{
    a += size - 1;
    b += size -1;
    long long minimum = 1e10;
    while (a<=b)
    {
        if(a % 2 ==1)
        {
            minimum = min(tree[a++],minimum);
        }
        if(b % 2 ==0)
        {
            minimum = min(tree[b--],minimum);
        }
        a/= 2;
        b/= 2;
    }
    return minimum;
}
 
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, q;
    long long max = 1e10;
    
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
    
    long long * tree = new long long [length]{max};
    
    for(int i=0; i<n; i++)
    {
        tree[n + i] = arr[i];
    }
    for(int i = n - 1; i>0; i--)
    {
        tree[i] =  min (tree[2 * i], tree[2 * i + 1]);
    }
    long long a, b, c;
    
    for(int k = 0; k< q; k++)
    {
        cin>>a>>b>>c;
        if(a == 1)
        {
            update(tree, n, b, c);
        }
        else
        {
            cout<<mini(tree, n, b, c)<<"\n";
        }
    }
    
    return 0;
}
