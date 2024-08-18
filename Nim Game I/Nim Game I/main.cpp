//
//  main.cpp
//  Nim Game I
//
//  Created by Yousef on 16.10.20.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long t, n, x1, x2, x3;
    cin>>t;
    while(t--)
    {
        cin>>n>>x1;
        n--;
        x3 = x1;
        while(n--)
        {
            cin>>x2;
            x1^= x2;
            x3 |= x2;
        }
        if(x3 == 0)
            cout<<"second";
        else
        {
            if(x1 == 0)
                cout<<"second"<<"\n";
            else
                cout<<"first"<<"\n";;
        }
        
        
    }
    return 0;
}
