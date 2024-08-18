//
//  main.cpp
//  Missing Number
///Users/yousef/Desktop/Competitive/Missing Number/Missing Number/main.cpp
//  Created by Yousef on 16.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int number;
    bool* arr;
    
    arr = new bool[n+1];
    
    for(int i = 1; i<n; i++)
    {
        scanf("%d",&number);
        arr[number] = 1;
    }
    for(int i = 1; i<=n; i++)
    {
      if(arr[i]==0)
      {
          cout<<i;
          break;
      }
    }
    
    
    
    
    return 0;
}
