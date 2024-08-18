//
//  main.cpp
//  Josephus Problem I
//
//  Created by Yousef on 03.02.21.
//

#include <iostream>
#include<vector>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;



typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    vector<int> ans, temp;
    cin>>n;
    indexed_set s;
    for(int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    int counter = 0, p = 1;
    
    while(counter < n)
    {
        if(s.size() == 1)
        {
            ans.push_back(*s.find_by_order(0));
            break;
        }
        ans.push_back(*s.find_by_order(p));
        counter++;
        if(p + 2 > s.size() - 1 )
        {
            if(p == s.size() - 1)
                p = 1;
            else
                p = 0;
            for(auto a: ans)
                s.erase(a);
        }
        else
            p += 2;
        
    }
    for(auto a: ans)
        cout<<a<<" ";
    return 0;
}
