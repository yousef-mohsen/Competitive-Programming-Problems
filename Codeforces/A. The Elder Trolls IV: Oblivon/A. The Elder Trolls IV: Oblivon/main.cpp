//
//  main.cpp
//  A. The Elder Trolls IV: Oblivon
//
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long x, y, z, k;
    long long ans = 0;
    cin>>x>>y>>z>>k;
    long long x1 = min(x,min(y,z));
    long long z1 = max (max(x,y), z);
    long long y1 = x + y + z - x1- z1;
    x1 = min (k/3, x1-1);
    k -= x1;
    y1 = min (k/2, y1-1);
    k-= y1;
    z1= min (k, z1-1);
    
    cout<<(x1+1)*(y1+1)*(z1+1);
    
    

    return 0;
}
