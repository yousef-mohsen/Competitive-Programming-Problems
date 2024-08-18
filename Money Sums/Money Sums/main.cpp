//
//  main.cpp
//  Money Sums
//
//  Created by Yousef on 04.05.20.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, p;
    cin>>n;
    set<long long>s;
    vector<int> v;
    vector<int> t;
    for(int i = 0; i < n; i++)
    {
        cin>>m;
        v.push_back(m);
    }
    
    for(auto e:v)
    {
        for(auto a:s)
        {
            t.push_back(a+e);
        }
        s.insert(e);
        while(t.size()!= 0)
        {
            p = t.back();
            t.pop_back();
            s.insert(p);
        }
    }
    cout<<s.size()<<"\n";
    for(auto n: s)
    {
        cout<<n<<" ";
    }
    return 0;
}
