//
//  main.cpp
//  Subarray Sum Queries
//
//  Created by Yousef on 28.01.21.
//

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll si;
vector<ll> p, s, t, sub;

void update(ll pos, ll value)
{
    pos += si - 1;
    p[pos] = value;
    s[pos] = value;
    t[pos] = value;
    sub[pos] = value;
    
    for(pos/= 2; pos>=1; pos/=2)
    {
        t[pos] = t[2 * pos] + t[2 * pos + 1];
        p[pos] = max(p[2 * pos],  t[2 * pos] + p[2 * pos + 1]);
        s[pos] = max(t[2 * pos + 1] + s[2 * pos], s[2 * pos + 1]);
        sub[pos] = max(sub[2 * pos], sub[2 * pos + 1]);
        sub[pos] = max(p[2 * pos + 1] + s[2 * pos], sub[pos]);
                           
    }
    
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m, c, x, k, inf = -1e17;
    cin>>n>>m;
    for(int i = 0; i <= 18; i++)
        if((1<<i) >= n)
        {
            c = i;
            break;
        }
    si = (1<<c);
    p.resize(2 * si + 1, 0);
    s.resize(2 * si + 1, 0);
    t.resize(2 * si + 1, 0);
    sub.resize(2 * si + 1, 0);
    
    for(int i = 1; i <= n; i++)
    {
        cin>>x;
        update(i, x);
    }
    for(int i = 1; i <= m; i++)
    {
        cin>>k>>x;
        update(k, x);
        cout<<sub[1]<<"\n";
    }
    return 0;
}
