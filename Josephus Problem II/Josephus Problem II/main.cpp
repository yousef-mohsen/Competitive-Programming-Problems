//
//  main.cpp
//  Josephus Problem II
//
//  Created by Yousef on 03.02.21.
//
 
#include <iostream>
#include<vector>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k;
    vector<int> ans, temp;
    cin>>n>>k;
    
    indexed_set s;
    for(int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    int counter = 0, p = k % n;
    //k++;
    while(counter < n)
    {
        if(s.size() == 1)
        {
            ans.push_back(*s.find_by_order(0));
            break;
        }
        int item = *s.find_by_order(p);
        ans.push_back(item);
        s.erase(item);
        counter++;
        
        if(p + (k % s.size()) > s.size() - 1 )
        {
            auto t = k;
            t -= s.size() - 1 - p;
            t--;
            p = t % s.size();
        }
        else
            p += k % s.size();
        
        
    }
    for(auto a: ans)
        cout<<a<<" ";
    return 0;
}
