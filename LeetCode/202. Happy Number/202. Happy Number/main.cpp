//
//  main.cpp
//  202. Happy Number
//
//  Created by Yousef on 10.06.26.
//

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int new_n, digit;
        
        while (n != 1)
        {
            if(s.count(n) != 0)
                return false;
            s.insert(n);
            new_n = 0;
            while (n)
            {
                digit = n % 10;
                digit *= digit;
                new_n += digit;
                n/= 10;
            }
            n = new_n;
        }
    
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.isHappy(2
                    );
    return 0;
}
