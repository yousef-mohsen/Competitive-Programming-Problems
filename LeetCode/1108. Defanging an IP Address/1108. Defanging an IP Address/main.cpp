//
//  main.cpp
//  1108. Defanging an IP Address
//
//  Created by Yousef on 27.05.26.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for(auto& s: address)
            if(s == '.')
                ans+= "[.]";
            else
            ans+= s;
            
        return ans;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
