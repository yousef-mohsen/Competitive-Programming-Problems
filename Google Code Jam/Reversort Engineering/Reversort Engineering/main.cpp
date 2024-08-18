//
//  main.cpp
//  Reversort Engineering
//
//  Created by Yousef on 26.03.21.
//


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll rev (vector<ll>  v)
{
    ll s = 0, m , p, n = v.size();
    for(int z = 0; z < n - 1; z++)
    {
        m = v[z];
        p = z;
        for(int k = z + 1; k < n; k++)
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
    return s;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
       ll t, n , c, n_m = 0, c_m = 0,  e = 2;
       cin>>t;
       
       vector<ll>l(t + 1);
       vector<ll>r(t + 1);
       for(int i = 1; i <= t; i++)
       {
           cin>>n>>c;
           n_m = max(n_m, n);
           c_m = max(c_m, c);
           l[i] = n;
           r[i] = c;
       }
       
       vector<vector<vector<ll>>> v(n_m + 1 , vector< vector<ll>>(c_m + 1, vector<ll>()));
       
       v[2][1] = vector<ll> {1,2};
       v[2][2] = vector<ll> {2,1};
       
    
    for(int i = 2; i < n_m ; i++)
    {
        
        int k = i - 1;
       
        while(true)
        
        {
            int counter = 0;
            
            for(int z = 0; z <= v[i][k].size(); z++)
            {
                vector<ll> co(0);
                for(int b = 0; b < v[i][k].size(); b++)
                
                {
                    if(b == counter)
                        co.push_back(i + 1);
                  
                    co.push_back(v[i][k][b]);
                }
                
                if(counter == v[i][k].size())
                    co.push_back(i + 1);
                counter ++;
                ll ans = rev(co);
                
                if(ans <= c_m)
               if(v[i + 1][ans].size() == 0)
               {
                   swap(v[i + 1][ans], co);
                   
               }
                
            }
            if(k == e || k == c_m)
                break;
            k = min (int(c_m),min(int(e), k + i + 1));
        }
        e += i + 1;
    }
    for(int i = 1; i <= t; i++)
    {
        n = l[i];
        c = r[i];
        if(v[n][c].size() == 0)
        {
            cout<<"Case #"<<i<<": "<<"IMPOSSIBLE"<<"\n";
        }
        else
        {
            cout<<"Case #"<<i<<": ";
            for(auto a: v[n][c])
                cout<<a<<" ";
        
            cout<<"\n";
        }
    }
    return 0;
}
