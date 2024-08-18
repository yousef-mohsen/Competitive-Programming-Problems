//
//  main.cpp
//  Median Sort
//
//  Created by Yousef on 27.03.21.
//

#include <iostream>
#include <vector>
#include <set>

typedef long long  ll;
using namespace std;

vector<set<ll>> b;
vector<set<ll>> s;
ll q;


void update(ll node, ll type, ll nu)
{
    
    // 1 = bigger
    if (type == 1)
    {
        if(b[node].count(nu) == 0)
        {
            b[node].insert(nu);
            for(auto a: b[node])
                for(auto z: s[node])
                    update(z,1,a);
            for(auto a: b[node])
                for(auto z: s[node])
                    update(a,0,z);
        }
    }
    else
    {
        if(s[node].count(nu) == 0)
        {
            s[node].insert(nu);
            for(auto a: b[node])
                for(auto z: s[node])
                    update(z,1,a);
            
            for(auto a: b[node])
                for(auto z: s[node])
                    update(a,0,z);
            
        }
    }

}
void cal(ll x, ll y, ll z)
{
   
    cout<<x<<" "<<y<<" "<<z<<endl;
    q--;
        if(!q)
            exit(0);
    
    ll m, ma, mi;
    cin>>m;
    set<ll> se;
    se.insert(x);
    se.insert(y);
    se.insert(z);
    se.erase(m);
    x = *(se.begin());
    se.erase(x);
    y = *(se.begin());
    if(m == - 1)
        exit(0);
    
    if(s[m].count(x) == 0 && s[y].count(x) ==0 && s[y].count(m) ==0 && b[m].count(y) == 0 && b[x].count(y) ==0)
    {
        ma = x; mi = y;
    }
    else
    {
        ma = y; mi = x;
    }
    
    update(mi, 1, ma);
    update(mi, 1, m);
    
    //b[mi].insert(ma);
    //b[mi].insert(m);
    
    update(m, 1, ma);
    update(m, 0, mi);
    
    //b[m].insert(ma);
    //s[m].insert(mi);
    
    update(ma, 0, mi);
    update(ma, 0, m);
    //s[ma].insert(mi);
    //s[ma].insert(m);
  
    for(auto a: b[ma])
    {
        update(m, 1, a);
        update(mi, 1, a);
        //b[m].insert(a);
        //b[mi].insert(a);
    }
    for(auto a: s[m])
    {
        update(ma, 0, a);
        //s[ma].insert(a);
    }
    for(auto a: b[m])
    {
        update(mi, 1, a);
        //b[mi].insert(a);
        
    }
    for(auto a: s[mi])
    {
        update(m, 0, a);
        update(ma, 0, a);
        //s[m].insert(a);
        //s[ma].insert(a);
    }
 
    
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll t, n, j;
    cin>>t>>n>>q;
    q *= t;
    
    
    for(int i = 1; i <= t; i++)
    {
        b = vector<set<ll>>(n + 1);
        s = vector<set<ll>> (n + 1);
        
        for(int z = 1; z <= n - 2; z++)
        for(int q = z + 1; q <= n - 1; q++)
        for(int p = q + 1; p <= n; p++)
        {
            if((b[z].size() + s[z]. size() == n - 1 && b[q].size() + s[q]. size() == n - 1 &&
               b[p].size() + s[p]. size() == n - 1)
               ||(z ==q || z == p || q == p ))
                continue;
            
            if((b[z].count(p)||s[z].count(p)) &&
               (b[z].count(q)||s[z].count(q)) &&
               (b[p].count(z)||s[p].count(z)) &&
               (b[p].count(q)||s[p].count(q)) &&
               (b[q].count(z)||s[q].count(z)) &&
               (b[q].count(p)||s[q].count(p)))
            {
                
                for(auto a: b[z])
                    for(auto l: s[z])
                        update(l,1,a);
                for(auto a: b[z])
                    for(auto l: s[z])
                        update(l,0,z);
                
                
                for(auto a: b[p])
                    for(auto l: s[p])
                        update(l,1,a);
                for(auto a: b[p])
                    for(auto l: s[p])
                        update(l,0,z);
                
                for(auto a: b[q])
                    for(auto l: s[q])
                        update(l,1,a);
                for(auto a: b[q])
                    for(auto l: s[q])
                        update(l,0,z);
                
                
                continue;
            }
            cal(z, q, p);
        }
        /*
        for(int z = 1; z <= n - 2; z++)
        {
            cal(z, z + 1, z + 2);
        }
        for
        
        for(int q = 1; q <= n; q ++)
        {
            ll start = 1, f1, f2;
            while(b[q].size() + s[q]. size() < n - 1)
            {
                if(start == q)
                    start ++;
                for(start; start <= n; start ++)
                {
                    
                    if(b[q].count(start) == 0 && s[q].count(start) == 0 && start != q)
                    {
                        f1 = start;
                        break;
                    }
                }
                if(b[q].size() + s[q]. size() == n - 2)
                {
                    ll a;
                    for(int w = 1; w <= n; w++)
                    {
                        if(w != f1 && w !=q)
                        {
                            a = w;
                            break;
                        }
                    }
                    cal(f1, q, a);
                }
                else
                {
                    for(start; start <= n; start ++)
                    {
                        if(b[q].count(start) == 0 && s[q].count(start) == 0 && start != f1 && start != q)
                        {
                            f2 = start;
                            break;
                        }
                    }
                    cal(f1, q, f2);
                }
                
            }
        }
        */
        set<pair<ll,ll>> ans;
        for(int w = 1; w <= n; w++)
        {
            ans.insert({b[w].size(),w});
        }
        for(auto a: ans)
            cout<<((a)).second<<" ";
        cout<<endl;
        
        cin>>j;
        if(j == -1)
            return 0;
        
    }
    
    
    return 0;
}

