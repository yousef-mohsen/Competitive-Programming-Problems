//
//  main.cpp
//  344. Reverse String
//
//  Created by Yousef on 10.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        
        while(l < r)
        {
            swap(s[l], s[r]);
            l ++;
            r --;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
