//
//  main.cpp
//  Projects
//
//  Created by Yousef on 10.09.20.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

typedef long long ll;

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    long n, a, b, p;

    cin>>n;
    vector<tuple<ll, ll, ll>> v;
    vector<ll> ans (n + 1);
    v.push_back(make_tuple(0,0,0));
    
    for(int i = 0; i < n; i ++)
    {
        cin>>a>>b>>p;
        v.push_back(make_tuple(b,a,p));
    }
    sort(v.begin(), v.end());
    ans[0] = 0;
    
    for(int i = 1; i <= n; i++)
    {
        auto t = lower_bound(v.begin(), v.end(),make_tuple(get<1>(v[i]),0 ,0));
        int pos = t - v.begin() - 1;
        ans[i] = max(ans[i - 1],ans[pos] + get<2>(v[i]));
    }
    cout<<ans[n];

    return 0;
}
