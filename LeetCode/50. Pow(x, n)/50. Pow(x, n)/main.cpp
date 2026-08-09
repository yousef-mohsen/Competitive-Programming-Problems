//
//  main.cpp
//  50. Pow(x, n)
//
//  Created by Yousef on 12.06.26.
//

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(n < 0)
            return 1/pow(x,abs(N));
        return pow(x, n);
        
    }
    double pow(double x, int n)
    {
        if (n == 0)
            return 1;
        if(x == 0)
            return 0;
        double u = pow(x, n / 2);
        if( n%2 == 0)
            return u*u;
        return u*u*x;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    cout<<INT_MIN<<"\n";
    cout<<s.pow(1.00000, -2147483648);
    return 0;
}
