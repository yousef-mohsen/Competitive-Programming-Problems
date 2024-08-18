//
//  main.cpp
//  Apple Division
//
//  Created by Yousef on 18.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
long long sum = INFINITY;
void search(int , int , bool [], long long []);

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    long long *arr = new long long [n];
    bool *taken = new bool [n];
    for(int i=0; i <n; i++)
    {
        cin>>arr[i];

    }
    search(n,0, taken, arr);
    cout<<sum;
    
    
    return 0;
}
void search(int size, int n, bool taken [], long long arr[])
{
    if(n == size)
    {
        long long sum1 = 0, sum2 = 0;
        for(int i =0; i<size; i++)
        {
            if(taken[i] == 1)
            {
                sum1 += arr[i];
            }
            else
            {
                sum2 += arr[i];
            }
        }
        sum = min(sum, abs(sum1-sum2));
        return;
    }
    
    taken[n] = 1;
    search (size, n+1, taken, arr);
    taken[n] = 0;
    search (size, n+1, taken, arr);
    
}
