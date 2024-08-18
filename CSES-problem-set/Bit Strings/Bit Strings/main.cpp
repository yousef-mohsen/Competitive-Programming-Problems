//
//  main.cpp
//  Bit Strings
//
//  Created by Yousef on 17.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    long long n;
    cin>>n;
    long long power = pow(10,9) + 7;
    long long ans = 1;
    for (int i=1; i<=n;i++)
    {
        ans=(ans*2) % power;
    }
    cout<<ans;
    
    return 0;
}
