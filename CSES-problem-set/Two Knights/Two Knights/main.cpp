//
//  main.cpp
//  Two Knights
//
//  Created by Yousef on 25.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
long long value;
using namespace std;

long long solve (long long n)
{
    if(n == 1)
    {
        cout <<0<<"\n";
        return 0;
    }
    
    value = solve (n - 1) + (2 * n * n * n) + (-3 * n *n) + (- 7 * n + 16);
    cout << value<<"\n";
    
    return value;
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    solve(n);
    
    return 0;
}
