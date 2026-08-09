//
//  main.cpp
//  69.Sqrt(x)
//
//  Created by Yousef on 19.05.26.
//

#include <iostream>
#include <limits>
using namespace std;

/*
class Solution {
public:
    int mySqrt(int x) {
        
        int l = 0, r = 46340, ans = 0, product = 0;
        while(l <= r)
        {
            ans = (l + r) / 2;
            product = ans * ans;
            if (product == x)
                return ans;
            if (product < x)
            {
                l = ans + 1;
                if (l * l > x)
                    return l - 1;
            }
            else
            {
                r = ans - 1;
                if (r*r < x)
                    return r;
            }
            
            
            
            
        }
        return l;
    }
};
 */


class Solution {
public:
    int mySqrt(int x) {

        long long  z = x;
        long long s = 0;
        for (long long b = z; b >= 1; b /= 2)
        {
            while((s+b) * (s+b) <= x)
            {
                s+= b;
            }
        }

        return s;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    //cout<<INT_MAX;
    cout<<s.mySqrt(2147483647);
    
    return EXIT_SUCCESS;
}
