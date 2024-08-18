//
//  main.cpp
//  Counting Divisors
//
//  Created by Yousef on 18.03.20.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    
    long long counter, x, product = 1;
    int p = 1e6;
    vector <bool> v (p + 1, false);
    v[1] = 1;
    
    for(int i = 2; i<= p; i++)
    {
        if(v[i])
            continue;
        for(int k = i + i; k < p + 1; k += i)
        {
            v[k] = true;
        }
    }
    
    
    for(int i = 0; i < n; i++)
    {
        cin>>x;
        counter = 0;
        product = 1;
        
        if(!v[x])
        {
            cout<<2<<"\n";
        }
        else
        {
            for(int k = 2; k * k <= x; k++)
            {
                counter = 0;
                while(x % k == 0)
                {
                    counter++;
                    x /= k;
                }
                product *= (counter + 1);
            }
            if(x > 1)
                product *= (2);
            cout<<product<<"\n";
            }
      
        }
    return 0;
}
