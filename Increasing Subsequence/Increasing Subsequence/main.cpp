//
//  main.cpp
//  Increasing Subsequence
//
//  Created by Yousef on 10.09.20.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a;
    cin>>n;
    vector<int> v;
    
    while(n--)
    {
        cin>>a;
        auto p = lower_bound(v.begin(), v.end(), a);
        if(p == v.end())
            v.push_back(a);
        else
            *p = a;
    }
    cout<<v.size();
    
    return 0;
}
