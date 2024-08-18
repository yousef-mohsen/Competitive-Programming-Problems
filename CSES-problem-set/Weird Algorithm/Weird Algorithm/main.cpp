//
//  main.cpp
//  Weird Algorithm
//
//  Created by Yousef on 16.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    long long n;
    cin>>n;
    
    while(n!=1){
        cout <<n<<" ";
        n= (n % 2 == 0) ? (n/2): (n*3 + 1 );
    }
    cout<<1;
}
