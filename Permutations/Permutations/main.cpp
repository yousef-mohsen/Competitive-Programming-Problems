//
//  main.cpp
//  Permutations
//
//  Created by Yousef on 17.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//





#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    
    if(n== 2|| n ==3)
    {
        cout<<"NO SOLUTION";
        return 0;
    }
    for(int i=2; i<=n; i+=2)
           cout<<i<<" ";
    
    for(int i =1; i<=n; i+=2)
       cout<<i<<" ";
       
       
   }
