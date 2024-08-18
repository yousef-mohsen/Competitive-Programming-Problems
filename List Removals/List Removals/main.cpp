//
//  main.cpp
//  List Removals
//
//  Created by Yousef on 19.09.20.
//

#include <iostream>
#include <iterator>
 #include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<pair<long long, long long> ,null_type,less<pair<long long, long long>>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main(int argc, const char * argv[]) {
  ios::sync_with_stdio(0); cin.tie(0);
  indexed_set s;
  long long n, x, p;
    cin>>n;
  for(int i = 1; i <=n; i++)
  {
      cin>>x;
      s.insert({i,x});
  }
  for(int i = 1; i <= n; i++)
  {
      cin>>p;
      auto value = s.find_by_order(p - 1);
                cout<<(*value).second<<" ";
        s.erase(s.find_by_order(p - 1));
  }

    return 0;
}
