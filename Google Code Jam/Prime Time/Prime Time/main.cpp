//
//  main.cpp
//  Prime Time
//
//  Created by Yousef on 10.04.21.
//

#include <iostream>
#include <vector>

typedef long long  ll;
using namespace std;

int main(int argc, const char * argv[]) {
    ll t, n , m, p;
    
    cin>>t;
    for(int i = 1; i <= t; i++)
    {
        cin>>n;
        vector<ll>v (n + 1);
        
        int pos = 1;
        for(int q = 1; q <= n; q++)
        {
            cin>>p>>m;
            for(int z = 1; z <= m; z++)
            {
                v[pos] = p;
                pos++;
            }
        }
        ll s = 0, mu = 1;
        vector<ll>sum(v.size());
        vector<ll>mult(v.size());
        sum[1] = v[1];
        mult[1] = v[1];
        mult[0] = 1;
        sum[0] = 0;
        v[0] = 1;
        for(int q = 2; q < v.size(); q++)
        {
            sum[q] = v[q] + sum[q - 1];
            mult[q] = v[q] * mult[q - 1];
        }
        ll max = 0;
        ll p1 = 0, p2 = v.size() - 1;
        ll product = v[v.size() - 1];
        while(p1 <= p2)
        {
            if(product == sum[p2] - sum[p1])
            {
                max = sum[p2] - sum[p1];
                product *= 
                p2 --;
            }
        }
        cout<<"Case #"<<"i"<<": "<<max<<"'\n";
        
    }

    return 0;
}
