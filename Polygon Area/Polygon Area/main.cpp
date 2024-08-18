//
//  main.cpp
//  Polygon Area
//
//  Created by Yousef on 08.03.21.
//

#include <iostream>

typedef long long ll;
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, x1, y1, x2, y2, a = 0, b , e;
    cin>>n>>x1>>y1;
    b = x1, e = y1;
    for(int i = 1; i < n; i++)
    {
        cin>>x2>>y2;
        a += y2 * x1 -x2 * y1 ;
        swap(x1, x2);
        swap(y1, y2);
    }
    a += x1 * e - y1 * b;
    
    if(a < 0)
        a *= -1;
    cout<<a;
    return 0;
}
