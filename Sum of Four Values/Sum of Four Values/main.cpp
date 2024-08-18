//
//  main.cpp
//  Sum of Four Values
//
//  Created by Yousef on 23.12.19.
//  Copyright © 2019 Yousef. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    long long x, y, sum;
    cin>>n>>x;
    vector <pair<long long, long long>> v;

    
    for(int i = 1; i <= n; i++)
    {
        cin>>y;
        v.push_back(make_pair(y, i));
    }
    if(n < 4 || x < 4)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    sort(v.begin(), v.end());
    auto it = lower_bound(v.begin(), v.end(), make_pair(x,0LL));
    v.erase(it, v.end());
    auto end_1 = v.end();
    advance(end_1, -3);
    auto end_2 = end_1;
    end_2 ++;
    for(auto i = v.begin(); i != end_1; i++)
        {
            sum = x - (*i).first;
            auto k = i;
            k++;
            
            for(k; k != end_2; k++)
            {
                sum = x - (*i).first - (*k).first;
                if(sum <1)
                    break;
                auto l = k;
                l++;
                auto r = v.end();
                r --;
                
                while (l != r)
                {
                    if(sum - (*l).first -(*r).first >0)
                    {
                        l++;
                    }
                    else if(sum - (*l).first -(*r).first <0 )
                    {
                        r--;
                    }
                    else
                    {
                        cout<< (*i).second<<" "<<(*k).second<<" "<<(*l).second<<" "<<(*r).second;
                        return 0;
                    }
                }
            }
                
        }
    

    cout<<"IMPOSSIBLE";
         
    return 0;
}
