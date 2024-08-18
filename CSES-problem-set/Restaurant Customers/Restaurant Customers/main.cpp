//
//  main.cpp
//  Restaurant Customers
//
//  Created by Yousef on 20.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int n;
    cin>>n;
    
    
    pair<long,char> * arr = new pair<long,char> [2*n];
    for(int i=0; i<n*2;i++)
    {
        cin>> arr[i].first;
        arr[i].second = 'C';
        cin>> arr[i+1].first;
        arr[i+1].second = 'G';
        i++;
    }
    sort (arr, arr+2*n);
    
    int counter = 0;
    int maximum = 0;
    for(int i =0; i< 2*n; i++)
    {
        if(arr[i].second == 'C')
        {
            counter ++;
        }
        else
        {
            counter --;
        }
        maximum = max(counter, maximum);
    }
   
    cout <<maximum;
    return 0;
}
