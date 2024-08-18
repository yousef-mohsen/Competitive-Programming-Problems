//
//  main.cpp
//  Stick Game
//
//  Created by Yousef on 16.10.20.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k, t;
    cin>>n>>k;
    vector<int> a (n + 2, 0);
    vector<int> v;
    while(k--)
    {
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    
    for(int i = 1; i <= n; i++)
    {
        for(auto t: v)
        {
            if(a[i] == 1)
            {
                cout<<"W";
                break;
            }
            if(i-t <0)
                break;
            if(a[i - t] == 0)
            {
                a[i] = 1;
                cout<<"W";
                break;
            }
            
            
        }
        if(a[i] == 0)
            cout<<"L";
    }
        
        
    
    return 0;
}
