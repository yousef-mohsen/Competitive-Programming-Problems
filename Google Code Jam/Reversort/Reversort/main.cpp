//
//  main.cpp
//  Reversort
//
//  Created by Yousef on 26.03.21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;


int main(int argc, const char * argv[]) {
    ll t, n, l, m, s, p;
    cin>>t;
    
    for(int i = 1; i <= t; i++)
    {
        cin>>n;
        vector<ll> v (n + 1);
        for(int i = 1; i <= n; i++)
            cin>>v[i];
        s = 0;
        for(int z = 1; z < n; z++)
        {
            m = v[z];
            p = z;
            for(int k = z + 1; k <= n; k++)
            {
                if(v[k] < m)
                {
                    p = k;
                    m = v[k];
                }
            }
            
            s += p - z + 1;
            reverse(&v[z], &v[p + 1]);
            
        }
        cout<<"Case #"<<i<<": "<<s<<"\n";
    }

    return 0;
}
