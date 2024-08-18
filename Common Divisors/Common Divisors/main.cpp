//
//  main.cpp
//  Common Divisors
//
//  Created by Yousef on 30.09.20.
//
 
#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m = -1, ans = 1;
    cin>>n;
    vector<int> v (n + 1);
    
    for(int i = 1; i <= n; i ++)
    {
        cin>>v[i];
        m = max(m, v[i]);
    }
    
    vector<int> s (m + 1, 0);
    vector<int> a (m + 1, 0);
    a[1] = 2;
    s[1] = 1;
    for(int i = 2; i <= m; i++)
    {
        for(int u = i; u <= m; u+= i)
        {
            if(!s[u])
                s[u] = i;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        vector<int> se;
        int k = v[i];
        if(k <= ans)
            continue;
        while(k > 1)
        {
            int m = se.size();
            for(int z = 0; z < m; z++)
            {
                se.push_back(s[k] * se[z]);
                if(a[se[se.size() - 1]] == 0)
                    a[se[se.size() - 1]] = i;
                else if(a[se[se.size() - 1]]!= i)
                    ans = max(ans, se[se.size() - 1]);
            }
            
            if(a[s[k]] == 0)
                a[s[k]] = i;
            else if(a[s[k]]!= i)
                ans = max(ans, s[k]);
            se.push_back(s[k]);
            k /= s[k];
        }
        
    }
    
    cout<<ans;
    
    return 0;
}
