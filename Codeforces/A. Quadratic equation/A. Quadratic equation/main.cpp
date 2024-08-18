//
//  main.cpp
//  A. Quadratic equation
//
//  Created by Yousef on 09.08.20.
//

#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, const char * argv[]) {
    double a, b, c;
    double ans1, ans2, r;
    cin>>a>>b>>c;
    
    r= sqrt(pow(b,2.0) +(-4*a*c));
    
    ans1 = ((-1*b)+r)/(2*a);
    ans2 = ((-1*b)-r)/(2*a);
    
    if(ans1== ans2)
    {
        cout<<ans1;
    }
    else
    {
        cout<<ans1<<" "<<ans2;
    }
    
   
    return 0;
}
