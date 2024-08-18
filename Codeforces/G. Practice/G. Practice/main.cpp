//
//  main.cpp
//  G. Practice
//
//  Created by y.m on 18.08.20.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[]) {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    float n;
    cin>>n;
    
    int z= ceil(log2(n));
    cout<<z<<"\n";
    vector<int> v;
    vector<int> ans;
    ans.push_back(0);
    
    for(int i = 0; i<=n; i++)
    {
        v.push_back(i);
    }
    
    for(int i = 1; i<=z; i++)
    {
        int k = 1<<i;
        
        for(int q=1; q<=n;q+=k)
        {
            for(int x=0; x<k/2; x++)
            {
                if(x + q<=n)
                ans.push_back(v[x+q]);
            }
                
        }
        
        cout<<ans.size()-1<<" ";
        
        for(int z= 1; z<=ans.size() - 1;z++)
        {
            cout<<ans[z]<<" ";
        }
        cout<<"\n";
        ans = vector<int>();
        ans.push_back(0);
    }
    
    
    
    


    return 0;
}
