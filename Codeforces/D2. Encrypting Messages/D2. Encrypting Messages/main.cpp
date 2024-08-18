//
//  main.cpp
//  D2. Encrypting Messages
//
//

#include <iostream>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, c;
    
    cin>>n>>m>>c;
    
    vector<int> v(n+1);
    vector<int> s(m+1,0);
    
    for(int i=1; i<=n;i++)
    {
        cin>>v[i];
    }
  
    for(int i = 1; i<=m; i++)
    {
        cin>>s[i];
        s[i]+=s[i-1];
    }
    
    int p1 =1, p2 = 1;
    
    for(int i = 1; i <= n; i++)
    {
        v[i]+= s[p2] - s[p1 - 1];
        cout<<v[i]%c<<" ";
        if(p2<m)
            p2++;
        if(i+m>n)
            p1++;
    }
    
    return 0;
}
