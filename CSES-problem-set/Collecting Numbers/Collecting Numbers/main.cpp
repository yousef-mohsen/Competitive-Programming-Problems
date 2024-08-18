//
//  main.cpp
//  Collecting Numbers
//
//  Created by Yousef on 31.01.21.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x, ans = 0, order = 1e9;
    cin>>n;
    vector<int> v (n + 1);
    
    for(int i = 1; i <= n; i++)
    {
        cin>>x;
        v[x] = i;
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(v[i] < order)
        {
            ans++;
        }
        order = v[i];
    }
    cout<<ans;
    return 0;
}
