//
//  main.cpp
//  Nearest Smaller Values
//
//  Created by Yousef on 28.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin>>n;
    
    long long * arr = new long long [n+1];
    int * position = new int [n+1];
    position [0] = 0;
    arr[0] = 200000000000;
    
    
    for(int i =1; i<=n; i++)
    {
        cin>>arr[i];
        if(arr[i-1] < arr[i])
        {
         cout<<i-1<<" ";
            position[i] = i-1;
        }
        else
        {
            bool test = false;
            int k = i-1;
            while(!test)
            {
                if(arr[position[k]] < arr[i])
                {
                    cout<<position[k]<<" ";
                    position[i] = position[k];
                    test = true;
                }
                else if(position[k] == 0)
                {
                        test = true;
                        cout<<0<<" ";
                        position[i] = 0;
                
                }
                else
                {
                    k = position[k];
                }
                    
            }
        }
    }
    
    return 0;
}
