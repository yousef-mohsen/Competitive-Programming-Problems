//
//  main.cpp
//  Missing Coin Sum
//
//  Created by Yousef on 30.01.21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, ans = 1;
    cin>>n;
    vector<ll> v (n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    sort(v.begin(), v.end());
    
    for(auto a: v)
    {
        if(ans < a)
            break;
        ans += a;
    }
    cout<<ans;


    return 0;
}
