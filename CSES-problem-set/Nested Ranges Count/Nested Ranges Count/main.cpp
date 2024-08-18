//
//  main.cpp
//  Nested Ranges Count
//
//  Created by Yousef on 06.02.21.
//

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <tuple>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;



int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, x, y, pos;
    cin>>n;
    vector<int> cd(n + 1, 0) , c(n + 1, 0);
    set<tuple<int, int, int>> s;
    
    for(int i = 1; i <= n; i++)
    {
        cin>>x>>y;
        s.insert({x,-y, i});
    }
    indexed_set ans;
    
    for(auto e: s)
    {
        if(ans.size() == 0)
        {
            ans.insert(get<1>(e));
            continue;
        }
            
        cd[get<2>(e)] = ans.order_of_key(get<1>(e) + 1);
        ans.insert(get<1>(e));
    }
    auto pointer = s.end();
    pointer--;
    indexed_set ans2;
    
    while(pointer != s.begin())
    {
        c[get<2>(*pointer)] = ans2.size() - ans2.order_of_key(get<1>(*pointer) );
        ans2.insert((get<1>(*pointer)));
        pointer--;
    }
    c[get<2>(*pointer)] = ans2.size() - ans2.order_of_key(get<1>(*pointer));
    
    
    for(int i = 1; i <= n; i++)
        cout<<c[i]<<" ";
    cout<<"\n";
    for(int i = 1; i <= n; i++)
        cout<<cd[i]<<" ";

    return 0;
}
