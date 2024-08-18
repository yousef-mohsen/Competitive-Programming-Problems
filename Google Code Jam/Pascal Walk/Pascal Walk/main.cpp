//
//  main.cpp
//  Pascal Walk
//
//  Created by Yousef on 02.04.21.
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <math.h>

using namespace std;
typedef long long ll;

int main(int argc, const char * argv[]) {
    map<pair<ll, ll>, ll> m;
    ll t, n, temp, sum, c, p, l;
    cin>>t;
    
    for(int i = 1; i <= 30; i++)
        for(int k = 1; k <= i; k++)
    {
        if(k == 1 || k == i)
            m[{i,k}] = 1;
        else
        {
            m[{i,k}] = m[{i - 1, k - 1}] + m[{i - 1,k}];
        }
    }
    
    for(int i = 1; i <= t; i++)
    {
        cin>>n;
        sum = 0;
        temp = n - 30;
        c = 1;
        l = 2;
        cout<<"Case #"<<i<<":"<<"\n";
        
        if(n <= 30)
        {
            while(sum < n)
            {
                cout<<c<<" "<<1<<"\n";
                sum++;
                c++;
            }
        }
        else
        {
            cout<<1<<" "<<1<<"\n";
            sum = 1;
            p = 1;
            
            for(int i = 1; i < 30 && (sum + pow(2, i) <= n); i++)
            {
                l = i;
             if((1<<i) & temp)
             {
                 if(p > 1)
                 {
                     for(; p >=1; p--)
                     {
                         cout<<i+1<<" "<<p<<"\n";
                         sum += m[{i + 1,p}];
                     }
                     p = 1;
                 }
                 else
                 {
                     for(; p <= i + 1; p++)
                     {
                         cout<<i +
                         1<<" "<<p<<"\n";
                         sum += m[{i + 1,p}];
                     }
                     
                 }
                 
             }
            else
            {
                cout<<i + 1<<" "<<p<<"\n";
                sum += 1;
                    
                if(p > 1)
                    p++;
                        
                }
            }
            l++;
            while(sum < n)
            {
                cout<<l + 1<<" "<<p<<"\n";
                l++;
                sum++;
                if(p != 1)
                    p++;
            }
        }
    }
     
        return 0;
}
