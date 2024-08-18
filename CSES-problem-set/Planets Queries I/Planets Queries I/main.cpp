//
//  main.cpp
//  Planets Queries I
//
//  Created by Yousef on 14.09.20.
//

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(int argc, const char * argv[]) {
    ll n, q, x, k;
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    vector<ll> v(n + 1);
    vector<vector<ll>> d (31, vector<ll> (n + 1));
    
    for(int i = 1; i <=n; i++)
    {
        cin>>v[i];
        d[0][i] = v[i];
    }
    
    for(int i = 1; i <= 30; i++)
    {
        for(int z = 1; z <= n; z++)
        {
            d[i][z] = d[i - 1][d[i - 1][z]];
        }
    }
    

    while(q--)
    {
        cin>>x>>k;

        for(int i = 0; i<=30; i++)
        {
            if(k & (1<<i))
                x=d[i][x];
        }
        cout<<x<<"\n";
    }
     
    
    
    return 0;
}
