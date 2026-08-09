//
//  main.cpp
//  171. Excel Sheet Column Number
//
//  Created by Yousef on 10.06.26.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        long long pow = 1, ans = 0, length = columnTitle.size();
        
        for(int i = length - 1 ; i >= 0; i--)
        {
            ans += (columnTitle[i] - 'A' + 1)* pow;
            pow *= 26;
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
