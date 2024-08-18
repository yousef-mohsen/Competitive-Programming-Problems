//
//  main.cpp
//  Apartments
//
//  Created by Yousef on 18.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,m;
    long long k ;
    cin>>n>>m>>k;
    
    vector<long long> desired;
    vector <long long >available;
    
    long long var;
    
    for(int i=0; i<n;i++)
    {
        cin>>var;
        desired.push_back(var);
    }
    
    for(int i=0; i<m;i++)
    {
         cin>>var;
        available.push_back(var);
    }
    
    sort(desired.begin(), desired.end());
    sort(available.begin(), available.end());
    
    int counter = 0;
    int i = 0, j = 0;
    while(i != desired.size()&& j !=available.size())
    {
        if(desired[i]-available[j]<-1*k)
        {
            i++;
            continue;
        }
        if(abs(desired[i]-available[j])<=k)
        {
            counter += 1;
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    cout<<counter;
    
    return 0;
}
