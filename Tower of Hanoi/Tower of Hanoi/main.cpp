//
//  main.cpp
//  Tower of Hanoi
//
//  Created by Yousef on 08.04.21.
//

#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;

vector<pair<ll, ll>> ans;

void hanoi(ll n, ll a, ll b, ll c)
{
    
    if(n == 1)
    {
        ans.push_back({a,c});
        return;
    }
    hanoi(n - 1, a, c, b);
    ans.push_back({a,c});
    hanoi(n - 1, b, a, c);
    
}


int main(int argc, const char * argv[]) {
    ll n;
    cin>>n;
    hanoi(n, 1, 2, 3);
    cout<<ans.size()<<"\n";
    
    for(auto a: ans)
        cout<<a.first<<" "<<a.second<<"\n";
        
    return 0;
}
