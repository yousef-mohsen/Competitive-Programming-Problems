//
//  main.cpp
//  Salary Queries
//
//  Created by Yousef on 05.01.21.
//
 
#include <iostream>
#include <vector>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, q, a, b;
    char c;
    indexed_set s;
    cin>>n>>q;
    vector<ll> e(n + 1);
    
    for(int i = 1; i <= n; i++)
    {
        cin>>e[i];
        s.insert(e[i]);
    }

    while(q--)
       {
           cin>>c>>a>>b;
           if(c == '?')
           {
     
               cout<<s.order_of_key(b + 1) - s.order_of_key(a)<<"\n";
           }
           else
           {
               
               s.erase(s.find_by_order(s.order_of_key(e[a])));
               s.insert(b);
               e[a] = b;
           }
       }
     
    return 0;
}
