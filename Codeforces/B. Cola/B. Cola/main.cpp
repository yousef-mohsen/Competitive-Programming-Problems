//
//  main.cpp
//  B. Cola
//
//  Created by Yousef on 13.08.20.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    double a, b, c;
    long long n, ans =0, t;
    
    cin>>n>>a>>b>>c;
    
    for(int i = 0; i <= a; i++)
        for(int k = 0; k<= b; k++)
        {
            double sum = n-0.5*i - k;
            if( sum>=0)
            {
                t = sum;
                if (!(sum > t))
                {
                    if((t&1) == 0)
                    {
                        t =t>>1;
                        if(t<=c)
                            ans+=1;
                    }
                }
            }
            
        }
    cout<<ans;

    return 0;
}
