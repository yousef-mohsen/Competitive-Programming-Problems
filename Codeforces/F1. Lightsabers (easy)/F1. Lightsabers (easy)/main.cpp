//
//  main.cpp
//  F1. Lightsabers (easy)
//
//

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, a, k=0;
    cin>>n>>m;
    
    vector<int> v(n + 1);
    vector<int> c (m + 1, 0);
    
    for(int i = 1; i<=n; i++)
    {
        cin>>a;
        v[i] = a;
    }
    
    for(int i = 1; i<=m; i++)
    {
        cin>>a;
        for(int n = 1; n <= a; n++)
        {
            c[i]+=1;
            k++;
        }
    }
    
    for(int i = 1; i <= n - k + 1; i++)
    {
        vector<int> test(m + 1,0);
        for(int m = 0; m < k; m++)
        {
            test[v[i+m]] += 1;
        }
        if(test == c)
        {
            cout<<"YES";
            return 0;
        }
    }
        
    cout<<"NO";
    
        return 0;
}
