//
//  main.cpp
//  Range Sum Queries II
//
//  Created by Yousef on 01.03.20.
//  Copyright © 2020 Yousef. All rights reserved.
//

#include <iostream>
using namespace std;

void update (long long* tree, int position, long long value, int size )
{
    while(position <= size)
    {
        tree[position] += value;

        position += position & -position;
    }
}

long long sum (long long* arr, int b)
{
    long long sum = 0;
    
    while(b >= 1)
    {
        sum += arr[b];
        b -= b&-b;
    }
    
    return sum;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, q, value, type;
    long long a, b;
    
    cin>>n>>q;
    
    long long *arr = new long long [n+1]{0};
    long long *tree = new long long [n+1]{0};
    for(int i=1; i<=n; i++)
    {
        cin>>value;
        arr[i] = value;
        update(tree, i, value, n);
    }
    
    for(int i = 0; i < q; i++)
    {
        cin>>type>>a>>b;
        
        if(type == 1)
        {
            update(tree, a, b - arr[a], n);
            arr[a] = b;
        }
        else
        {
         cout<<sum(tree, b) - sum(tree, a - 1)<<"\n";
        }
    }
    return 0;
}
