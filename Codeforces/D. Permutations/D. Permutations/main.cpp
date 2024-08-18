//
//  main.cpp
//  D. Permutations
//
//  Created by Yousef on 12.08.20.
//

#include <iostream>
#include <vector>

using namespace std;


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, a, m = 0, m2;
    cin>>n;
    
    vector<int> v (n + 2, 0);
    vector<int> s;
    
    while(n--)
    {
        cin>>a;
        s.push_back(a);
        v[a] +=1;
        m = max(m,a);
    }
    m2 = v[1];
    for(int i = 2; i <=m; i++)
    {
        m2 = max (m2, v[i]);
        if(v[i] > v[i-1])
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<m2<<"\n";
    for (auto k: s)
    {
        cout<<v[k]<<" ";
        v[k] --;
        
    }
    
    
    

    return 0;
}
