//
//  main.cpp
//  Sliding Cost
//
//  Created by Yousef on 27.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,k;
    cin>>n>>k;
    
    long long * arr = new long long [n];
    
    for (int i = 0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    for(int i = 0; i <= n - k; i++)
    {
        for (int l=0; l < k; l++)
        {
            
        }
    }
    
    return 0;
}
