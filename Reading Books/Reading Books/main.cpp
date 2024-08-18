//
//  main.cpp
//  Reading Books
//
//  Created by Yousef on 14.03.20.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    long long t, sum, m;
    
    cin>>n>>t;
    sum = t;
    m = t;
    
    for(int i = 1; i < n; i++)
    {
        cin>>t;
        sum += t;
        m = max(m, t);
    }
    
    if(m >= sum - m)
    {
        cout<<2 * m;
    }
    else
    {
        cout<< sum;
    }
    
    return 0;
}
