//
//  main.cpp
//  Counting Bits
//
//  Created by Yousef on 02.01.21.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n, ans = 0, temp, temp2;
    cin>>n;
    
    int counter = 0;
    
    
    for(int i = 0; i < 64; i++)
    {
        if(n &(1LL<<i))
        {
            counter = i;
        }
    }
    n++;
    for(int i = 0; i <= counter; i++)
    {
        temp = n % (1LL<<i);
        temp2= n  - temp;
        temp2 = (temp2/(1LL<<i));
        if(temp2 % (2))
            ans+= temp;
        temp2/=2;
        ans+=temp2*((1LL<<i));
    }
    cout<<(ans);
    return 0;
}
