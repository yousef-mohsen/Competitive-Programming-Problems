//
//  main.cpp
//  Book Shop
//
//  Created by Yousef on 27.02.20.
//  Copyright © 2020 Yousef. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,x;
    long long maxi =0LL;
    cin>>n>>x;
    
    long long *price = new long long [n];
    long long *pages = new long long [n];
    long long *sum= new long long [x+1]{0};
    
    for(int i=0; i<n; i++)
    {
        cin>>price[i];
    }
    
    for(int i=0; i<n; i++)
    {
        cin>>pages[i];
    }
   
    for(int k=0;k<n;k++)
    {
        for(int i = x; i - price[k] >= 0 ; i--)
        {
            if(sum [i -price[k]] !=0 || i-price[k] ==0 )
            {
                sum[i] = max(sum[i],sum[i-price[k]] + pages[k]);
                maxi = max(maxi, sum[i]);
            }
        }
      
    }
    cout<<maxi;
    return 0;
}
