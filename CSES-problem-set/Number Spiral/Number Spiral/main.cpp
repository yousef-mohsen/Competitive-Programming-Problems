//
//  main.cpp
//  Number Spiral
//
//  Created by Yousef on 17.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    long long t, y, x, bigger;
    cin>>t;
    long long  *arr = new long long [t];
    for(int i=0; i<t; i++)
    {
        cin>>y>>x;
        bigger = max(y,x);
        bigger = bigger*bigger - bigger+1;
        if(y==x)
        {
            arr[i] = bigger;
        }
        else if(max(y,x)%2==0)
        {
            if(y>x)
            
            {
                cout <<bigger + abs(x-y)<<"\n";
            }
            else
            {
              cout <<bigger - abs(x-y)<<"\n";
            }
        }
        else
        {
            if(x>y)
            
            {
                cout <<bigger + abs(x-y)<<"\n";
            }
            else
            {
                cout <<bigger - abs(x-y)<<"\n";
            }
                
        }
            
    
    }
   
    return 0;
}
