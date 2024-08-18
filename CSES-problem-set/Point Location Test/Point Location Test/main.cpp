//
//  main.cpp
//  Point Location Test
//
//  Created by Yousef on 03.03.21.
//
 
#include <iostream>

 
using namespace std;
typedef long long ll;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, x1, x2, x3, y1, y2, y3;
    cin>>t;
    
    while(t--)
    {
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        x2 -= x1;
        x3 -= x1;
        y2 -= y1;
        y3 -= y1;
        
        ll ans = x3 * y2 - y3 * x2;
        if(ans > 0)
            cout<<"RIGHT\n";
        else if(ans < 0)
            cout<<"LEFT\n";
        else
            cout<<"TOUCH"<<"\n";
    }
        
    
    return 0;
}
