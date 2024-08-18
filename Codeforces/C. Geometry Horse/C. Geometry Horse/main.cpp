//
//  main.cpp
//  C. Geometry Horse
//
//  Created by y.m on 23.08.20.
//

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n, a, b, m, ans = 0, f = 1;
    cin>>n;
    vector< pair<long long , long long >> v( n + 1);
    
    
    for(int i = 1; i <= n; i++)
    {
        
        cin>>v[i].second>>v[i].first;
    }
   sort(v.begin(), v.end());
    
    cin>>m;
    
    vector<long long> p;
    
    while(m--)
    {
        cin>>a;
        p.push_back(a);
    }
    long long i = 1, w = 1, q = 0, counter = 0;
    
    while (i < v.size())
    {
        if(q == p.size())
        {
            ans+= v[i].first * w *v[i].second;
            i++;
            continue;
        }
        if(v[i].second + counter < p[q])
        {
            ans+= v[i].first * w *v[i].second;
            counter += v[i].second;
            i++;
            
        }else if(v[i].second + counter == p[q])
        {
            ans+= v[i].first * w * v[i].second;
            counter +=v[i].second;
            i++;
            q++;
            w++;
        }
        else
        {
            v[i].second-= (p[q] - counter);
            ans+= v[i].first * w * (p[q]- counter);
            counter += p[q]- counter;
            w++;
            q++;
        }
    }
    cout<<ans;
    return 0;
}
