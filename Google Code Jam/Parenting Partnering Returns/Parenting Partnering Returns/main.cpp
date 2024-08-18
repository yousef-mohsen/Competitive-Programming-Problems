//
//  main.cpp
//  Parenting Partnering Returns
//
//  Created by Yousef on 24.03.21.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <tuple>

typedef long long ll;
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, n , b, e, c, C, J;
    bool s;
    cin>>t;
    
    for(int i = 1; i <= t; i++)
    {
        cin>>n;
        s = 1;
        vector<tuple<ll, ll, ll>> v;
        vector<char> ans (n + 1);
        
        for(int k = 1; k <= n; k++)
        {
            cin>>b>>e;
            v.push_back({b, 2, k});
            v.push_back({e, 1, k});
        }
        sort(v.begin(), v.end());
        
        c = 0;
        for(auto t: v)
        {
            if(get<1>(t) == 2)
                c ++;
            else
                c--;
            if(c == 3)
            {
                cout<<"Case #"<<i<<": "<<"IMPOSSIBLE";
                s = 0;
                break;
            }
        }
        if(s)
        {
            C = 0, J = 0;
        
            for(auto t: v)
            {
                if(get<1>(t) == 2)
                {
                    if(C == 0)
                    {
                        C = get<2>(t);
                        ans[get<2>(t)]= 'C';
                        
                    }
                    else
                    {
                        J = get<2>(t);
                        ans[get<2>(t)] = 'J';
                        
                    }
                }
                else
                {
                    if(get<2>(t) == C)
                        C = 0;
                    else
                    J = 0;
                }
            }
            cout<<"Case #"<<i<<": ";
            for(int z = 1; z <= n; z++)
                cout<<ans[z];
        }
        
        
        cout<<"\n";
    }

    return 0;
}
