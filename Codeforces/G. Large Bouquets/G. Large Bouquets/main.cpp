//
//  main.cpp
//  G. Large Bouquets
//
//  Created by Yousef on 14.08.20.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long e=0, o=0, a, n;
    
    cin>>n;
    while(n--)
    {
        cin>>a;
        if((a&1) ==1)
        {
            o+=1;
        }
        else
        {
            e+=1;
        }
    }
    if(e>=o)
    {
        cout<<o;
    }
    else
    {
        cout<<e + (o-e)/3;
        
    }
 
    
    
    return 0;
}
