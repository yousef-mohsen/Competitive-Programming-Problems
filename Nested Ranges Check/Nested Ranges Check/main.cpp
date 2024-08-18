//
//  main.cpp
//  Nested Ranges Check
//
//  Created by Yousef on 05.02.21.
//
 
#include <iostream>
#include <tuple>
#include <set>
#include <vector>
#include <utility>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef long long ll;
using namespace std;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, x, y;
    cin>>n;
    
    set<tuple<ll,ll,ll>> s;
    vector<ll> start(n + 1), co(n + 1, 0), cd(n + 1, 0);
 
    indexed_set ans;
 
    for(int i = 1; i <= n; i++)
    {
        cin>>x>>y;
        s.insert({x, y, i});
        s.insert({y, - x, i});
        start[i] = x;
        
    }
    ll ref  = -1e17;
    
    for(auto e: s)
    {
     if(get<1>(e) < 0)
     {
         int p = ans.order_of_key(-1 * get<1>(e));
         bool test = (*ans.find_by_order(p + 1) == (-1 * get<1>(e)));
         
       if(p != 0 || (ans.size() > 1 && test))
       {
        cd[get<2>(e)] = 1;
       }
         if(start[get<2>(e)] <= ref)
             co[get<2>(e)] = 1;
         ans.erase(ans.find_by_order(ans.order_of_key(-1 * get<1>(e))));
         
         
         ref = max(ref, -1 * get<1>(e));
     }
    else
        {
            
            ans.insert(get<0>(e));
        }
         
    }
    for(int i = 1; i <= n; i++)
    {
        cout<<co[i]<<" ";
    }
    cout<<"\n";
    
    for(int i = 1; i <= n; i++)
    {
        cout<<cd[i]<<" ";
    }
     
    return 0;
}
