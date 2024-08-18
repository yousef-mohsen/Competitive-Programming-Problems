//
//  main.cpp
//  Two Sets II
//
//  Created by Yousef on 08.09.20.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    long long sum = n * (n + 1), mo = 1e9 + 7;
    if((sum) & (1<<1))
    {
        cout<<0;
        return 0;
    }
    sum = sum>>1;
    
    vector<long long> p (sum + 1, 0);
    p[0] = 1;
    
    for(int i = 1; i<= n; i++)
        for(int k = sum ; k>=i; k--)
        {
            p[k] += p[k - i];
            while(p[k]>= mo)
                p[k]-=mo;
        }
    
    if((p[sum>>1])%2 == 1)
        cout<<((p[sum>>1])/2) + 500000004;
    else
        cout<<(p[sum>>1])/2;
    
    
    
    return 0;
}
