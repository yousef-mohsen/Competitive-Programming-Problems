//
//  main.cpp
//  Subarray Sums II
//
//  Created by Yousef on 13.03.20.
//

#include <iostream>
#include <vector>
#include "map"
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n;
    long long x, sum , value, ans = 0;;
    cin>>n>>x;
    map<long long, int > m;
    m[0]=1;
    cin>>value;
    sum = value;
    ans+= m[x-value];
    m[sum] +=1;
    
    
    
    for(int i = 1; i < n; i++)
    {
        cin>>value;
        sum+= value;
        ans+= m[sum-x];
        m[sum]+=1;
    }
    
    cout<<ans;
     

    
    return 0;
}
