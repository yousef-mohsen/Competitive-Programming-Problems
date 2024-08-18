//
//  main.cpp
//  Subarray Distinct Values
//
//  Created by Yousef on 06.02.21.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k, start = 1, x, ans = 0;
    cin>>n>>k;
    set <ll> s;
    multiset<ll> m;
    vector<ll> v(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin>>v[i];
        
        s.insert(v[i]);
        m.insert(v[i]);
        if(s.size() <= k)
            ans+= m.size();
        else
        {
            while(s.size() > k)
            {
                if(m.count(v[start]) == 1)
                {
                    s.erase(v[start]);
                    m.erase(v[start]);
                    start++;
                    ans+= m.size();
                    break;
                }
                m.erase(m.find(v[start]));
                start++;
            }
        }
    }
    cout<<ans;
    return 0;
}
