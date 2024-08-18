//
//  main.cpp
//  Trailing Zeros
//
//  Created by Yousef on 18.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    long long n;
    cin>>n;
    long long sum = 0;
    int i=1;
    
    while(pow(5,i)<=n)
    {
        sum+= n/pow(5,i);
        i++;
    }
    cout <<sum;
    return 0;
}
