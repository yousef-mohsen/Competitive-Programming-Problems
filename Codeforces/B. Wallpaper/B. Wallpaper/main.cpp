//
//  main.cpp
//  B. Wallpaper
//
//  Created by y.m on 22.08.20.
//

#include <iostream>
#include<cmath>
#include <vector>
#include <tuple>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    long long n, l, w, m, l_r, w_r, h_r, p, ans = 1e12, s = 0;
    double area;
        
    cin>>n;
    vector <tuple<long long, long long, long long>> r (n+1);
   
    
    for(int i= 1; i<=n; i++)
    {
        cin>>l_r>>w_r>>h_r;
        r[i] = make_tuple(l_r, w_r, h_r);
    }
    cin>>m;
     vector <tuple<long long, long long, long long>> paper (m+1);
    
    
    for(int i= 1; i<=m; i++)
    {
        cin>>l>>w>>p;
        paper[i] = make_tuple(l, w, p);
    }
    
    
    for(int i =1; i<=n; i++)
    {
        area = (2 * get<0>(r[i]) * get<2>(r[i])) + (2 * get<1>(r[i]) * get<2>(r[i]));
        
        ans = 1e12;
        
        for(int q =1; q<=m; q++)
        {
            if(get<0>(paper[q])<get<2>(r[i]))
                continue;
            
            
            l = (get<0>(paper[q])/get<2>(r[i]))*get<2>(r[i]);
            long long temp = ceil(area/(l*get<1>(paper[q])));
            ans = min(ans, get<2>(paper[q])*(temp));
        }
        s+=ans;
    }
    cout<<s;
    
    return 0;
}
