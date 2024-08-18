//
//  main.cpp
//  Grid Paths (dynamic)
//
//  Created by Yousef on 27.02.20.
//  Copyright © 2020 Yousef. All rights reserved.
//
 
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    long long mo = 1e9 +7;
    char c;
    
    bool** arr = new bool* [n];
    for(int i = 0; i<n; i++)
    {
        arr[i] = new bool[n];
    }
    
    for (int i = 0; i<n; i++)
    {
        for(int k =0; k<n; k++)
        {
            cin>>c;
            if(c == '*')
            {
                arr[i][k] = false;
                
            }
            else
            {
                arr[i][k] = true;
            }
        }
    }
    
    long long ** arr2 = new long long* [n];
      
    for(int i = 0; i<n; i++)
      {
          arr2[i] = new long long[n];
      }
    
    if(arr[0][0] ==true)
    {
        arr2[0][0] = 1LL;
    }
    
    for (int i = 0; i<n; i++)
      {
          for(int k =0; k<n; k++)
          {
             if(arr[i][k] == false)
             {
                 continue;
             }
              
              if(i+1 <n && arr[i+1][k])
                {
                  arr2[i+1][k] += arr2[i][k];
                    if (arr2[i+1][k] >mo)
                    {
                        arr2[i+1][k] -=mo;
                    }
                }
              
              if(k+1 <n && arr[i][k+1])
              {
                  arr2[i][k+1] += arr2[i][k];
                  if (arr2[i][k+1] >mo)
                    {
                        arr2[i][k+1] -=mo;
                    }
                                 
              }
             
          }
      }
    
    
    
    cout<<arr2[n-1][n-1];
    
    return 0;
}
