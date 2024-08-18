//
//  main.cpp
//  A. Reflection
//
//  Created by y.m on 25.08.20.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    long long a, b, c1, c2, v;
    
    cin>>a>>b;
    
    c1 = (to_string(a)).size();
    c2 = (to_string(b)).size();
    
    v  = pow (10.0 , c2);
    v -= 1;
    
    if(a <= (v / 2) && (v / 2) <= b)
    {
        cout<<(v/2) * (v/2 + 1);
        return 0;
    }

    if(c2 == c1 )
    {
            if(abs((v/2) - b)< abs((v/2) - a))
                cout<<b*(v-b);
            else
                cout<<a*(v-a);
    }
    if(c2 > c1)
        cout<<(v-b)*b;


    return 0;
}
