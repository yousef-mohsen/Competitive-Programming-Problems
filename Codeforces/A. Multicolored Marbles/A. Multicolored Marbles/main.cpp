//
//  main.cpp
//  A. Multicolored Marbles
//
//  Created by Yousef on 17.08.20.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    long long a = 1, b = 1, c = 0, sum = 1;
    int mo = 1000000007;
    cin>>n;
    
    for(int i = 2; i<=n; i++)
    {
        if(a>mo)
            a%=a;
        if(b>mo)
            b%=b;
        
        c = a + b;
        
        if(c>mo)
            c%=mo;
        sum +=c;
        
        if(sum>mo)
            sum%=mo;
        a = b;
        b = c;
    }
    
    cout<<sum;
    
    
    return 0;
}
