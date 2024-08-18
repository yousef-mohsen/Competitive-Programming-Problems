//
//  main.cpp
//  Hotel Queries
//
//  Created by Yousef on 19.09.20.
//

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m, r, size = 0, t, temp;
    cin>>n>>m;
    t = n;
    if(!(n&(n-1)))
        size = t;
    else
    {
        while(t!=0)
        {
            t = t>>1;
            size += 1;
        }
        size = 1<<size;
    }
    vector<ll> v (2 * size + 1, 0);
    t = 2 * size;
  
    for(int i = 0 ; i < n; i++)
    {
        cin>>v[size + i];
    }
    temp = t / 2;
    for(int i = temp; i < t; i +=2)
        for(int k = i/2; k >= 1; k/=2)
        {
            v[k] = max(v[2 * k], v[ 2 * k + 1]);
        }
    
    while(m--)
    {
        cin>>r;
        if(v[1]<r)
        {
            cout<<0<<" ";
            continue;
        }
        int i = 1;
        while(i < temp)
        {
            if(v[2 * i] >= r)
            {
                i = 2 * i;
            }
            else
            {
                i= i * 2 + 1;
                
            }
        }
        cout<<i - temp + 1<<" ";
        v[i]-= r;
        for(i/=2; i>= 1;i/=2)
        {
            v[i] = max(v[2*i], v[2*i + 1]);
        }
    }
    return 0;
}
