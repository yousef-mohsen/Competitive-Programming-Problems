//
//  main.cpp
//  Distinct Values Queries
//
//  Created by Yousef on 11.01.21.
//
 
#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>
#include <tuple>
 
using namespace std;
 
typedef long long ll;
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, q, s, a, b, ds = 0, c = 1, begin, end;
    cin>>n>>q;
    s = sqrt(n);
    vector<ll> ans(q + 1);
    vector<pair<ll, ll>> v;
    vector<tuple<ll, ll, ll, ll>> qs;
    vector<ll> p (n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin>>a;
        v.push_back({a, i});
    }
    
    for(int i = 1; i <= q; i++)
    {
        cin>>a>>b;
        qs.push_back( make_tuple(a / s, b, a, i));
    }
    
    sort(v.begin(), v.end());
    sort(qs.begin(), qs.end());
    p[v[0].second] = 1;
    
    for(int i = 1; i < v.size(); i++)
    {
        if(v[i].first == v[i - 1].first)
        {
            p[v[i].second] = c;
        }
        else
        {
            c++;
            p[v[i].second] = c;
        }
    }
    vector<ll> m (c + 1, 0);
    vector<ll> taken (n + 1, false);
    
 
    begin = get<2>(qs[0]);
    end = begin;
    
    for(int i = 0; i < qs.size(); i++)
    {
        a = get<2>(qs[i]);
        b = get<1>(qs[i]);
        
        if(end < b)
        {
            while(end <= b)
            {
                if(!taken[end])
                {
                    taken[end] = 1;
                    if(m[p[end]] == 0)
                        ds++;
                    m[p[end]]++;
                }
                end++;
            }
        }
        else
        {
            while(end > b)
            {
                if(taken[end])
                {
                    taken[end] = false;
                    if(m[p[end]] == 1)
                        ds--;
                    m[p[end]]--;
                }
                end--;
            }
            
        }
        
        if(begin < a)
        {
            while(begin < a)
            {
                if(taken[begin])
                {
                    m[p[begin]]--;
                if(m[p[begin]] == 0)
                    ds--;
                }
                taken[begin] = false;
                begin++;
            }
            a = begin;
        }
        else
        {
            while(a <= begin)
            {
                if(!taken[begin])
                {
                    taken[begin] = true;
                    if(m[p[begin]] == 0)
                        ds++;
                    m[p[begin]]++;
                }
                begin--;
            }
            
        }
        
        begin = a;
        end = b;
        ans[get<3>(qs[i])] = ds;
    }
        
    for(int i = 1; i < ans.size(); i++)
    cout<<ans[i]<<"\n";
 
    
    return 0;
}
