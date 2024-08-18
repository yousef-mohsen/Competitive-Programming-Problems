//
//  main.cpp
//  Range Update Queries
//
//  Created by Yousef on 03.03.20.
//  Copyright © 2020 Yousef. All rights reserved.
//

#include <iostream>
using namespace std;
void update (long long * tree, int size, long long value, int position)
{
    
    position += size;
    if(position >= 2 * size)
    {
        return;
        
    }
    tree[position] += value;
    
    for(position /= 2; position >= 1; position /= 2)
    {
        tree[position] = tree[2 * position] + tree[2 * position + 1];
    }
    
}

long long sum (long long * tree, int size, int a, int b)
{
    a += size;
    b += size;
    long long sum = 0;
    while(a<= b)
    {
        if((a & 1) == 1)
        {
            sum += tree[a++];
        }
        if((b & 1) == 0)
        {
            sum += tree[b--];
        }
        a /= 2;
        b /= 2;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q, position;
    long long value, type, a, b;
    
    cin>>n>>q;
    
    int length = 1;
    while(length < n)
    {
        length = length<< 1;
    }
    
    long long *tree = new long long [2 * n + 1]{0};
    long long *original = new long long [n + 1]{0};
    
    for(int i = n; i < 2 * n; i ++)
    {
        cin>>value;
        original[i - n + 1] = value;
        tree[i] = value - original[i - n];
        
    }
    
    for(int i = n - 1; i > 0; i --)
    {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    
    for(int i = 0; i < q; i++)
    {
        cin>>type;
        if(type == 1)
        {
            cin>>a>>b>>value;
            update(tree, n, value, a - 1);
            update(tree, n, - 1 * value, b);
            
        }
        else
        {
            cin>>position;
            cout<<sum(tree, n, 0, position - 1)<<"\n";
        }
        
    }

    
    return 0;
}
