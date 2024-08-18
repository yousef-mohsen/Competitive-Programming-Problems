//
//  main.cpp
//  Polygon Lattice Points
//
//  Created by Yousef on 19.03.21.
//

#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;

ll gcd (ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


ll cal(ll x1, ll y1, ll x2, ll y2)
{
    ll dif = y2 - y1;
    ll dif2 = (x2 - x1);
    if(dif < 0)
        dif *= -1;
    if(dif2 < 0)
        dif2 *= -1;
    
    ll ans = gcd(max(dif, dif2), min(dif, dif2));
    return ans;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, x1, y1, x2, y2, a = 0, b , e, boun;
    
    cin>>n>>x1>>y1;
    boun = 0;
    b = x1, e = y1;
    for(int i = 1; i < n; i++)
    {
        cin>>x2>>y2;
        a += y2 * x1 -x2 * y1 ;
        boun += cal(x1, y1, x2, y2);
        swap(x1, x2);
        swap(y1, y2);
        
    }
    boun += cal(b, e, x1, y1);
    
    a += x1 * e - y1 * b;
    if(a < 0)
        a *= -1;
    
    cout<<(a - boun + 2)/2<< " "<<boun;
    return 0;
}
