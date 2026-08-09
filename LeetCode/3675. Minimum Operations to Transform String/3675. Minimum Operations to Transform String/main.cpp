//
//  main.cpp
//  3675. Minimum Operations to Transform String
//
//  Created by Yousef on 14.06.26.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        //int length = 'z' - 'a' + 1;
        //vector<bool> v(length, false);
        int size = s.size(), m = 0;
        
        for(int i = 0; i <size; i++)
        {
            if(s[i] == 'a')
                continue;
            
            m = max (m, 26 - s[i] + 'a');
            if(m == 25)
                return 25;
        }
        return m;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.minOperations("yz");
    return 0;
}
