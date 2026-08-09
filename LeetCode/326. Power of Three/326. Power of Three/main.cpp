//
//  main.cpp
//  326. Power of Three
//
//  Created by Yousef on 10.06.26.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        
        long long  temp = n;
        if(n <= 0)
            return false;
        long ans = 1;
        while(temp >= 3)
        {
            temp/=3;
            ans*= 3;
            
        }
        
        if(ans == n)
           return true;
        return false;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.isPowerOfThree(9);
    return 0;
}
