//
//  main.cpp
//  Sum of Three Values
//
//  Created by Yousef on 23.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <set>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
   
    int n;
    long long x;
    multimap<long long, long long> s;
    long long value, tmp_1, tmp_2;
   
    cin>>n>>x;
   
    if(n == 1)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    
    for(int i = 1; i<=n; i++)
    {
        cin>>value;
        s.insert(make_pair(value,i));
    }
    
    auto t = s.lower_bound(x);
    s.erase(t, s.end());
    
   
    auto end = s.end();
    auto begin = s.begin();
    begin++;
    advance (end, -2);
    auto end_1 = (s.end());
    advance (end_1,-1);
    
    for(auto o = s.begin(); o!= end ; o++)
    {
        tmp_1 = o->first;
        
        auto i =o;
        ++i;
        for(i; i != end_1; i ++)
        {
            if(i->first + tmp_1 > x)
            {
                break;
            }
            auto it_2 = s.find(x - tmp_1 - (i->first));
            
            
            if(it_2 == s.end())
            {
                continue;
            }
            else
            {
                tmp_2 = i->first;
                
                if((it_2->second == o->second) || (it_2->second == i->second))
                    
                {
                    auto lower = s.lower_bound(it_2->first);
                    auto upper = s.upper_bound(it_2->first);
                    for(auto k = lower; k != upper; k++)
                    {
                        if(k->second != o->second  && k->second != i->second)
                        {
                            cout<<o->second<<" "<<i->second<<" "<<k->second;
                            return 0;
                        }
                    }
                }
                else
                {
                    cout<<o->second<<" "<<i->second<<" "<<it_2->second;
                    return 0;
                }
                
                    
            }
        }
        
    }

    cout<<"IMPOSSIBLE";
     
    
    return 0;
}

