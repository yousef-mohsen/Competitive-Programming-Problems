//
//  main.cpp
//  Nim Game II
//
//  Created by Yousef on 18.10.20.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long t, n, v, x;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        v = x % 4;
        while(--n)
        {
            cin>>x;
            v^= (x % 4);
        }
        if(v)
            cout<<"first"<<"\n";
        else
            cout<<"second"<<"\n";
        
    }
    return 0;
}
