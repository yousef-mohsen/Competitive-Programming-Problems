//
//  main.cpp
//  3407. Substring Matching Pattern
//
//  Created by Yousef on 27.05.26.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        
        string prefix = "", suffix = "";
        size_t pos = p.find('*');
        prefix = p.substr(0, pos);
        suffix = p.substr(pos + 1);
        
        if(prefix.size() && suffix.size())
        {
            pos = s.find(prefix);
            if(pos != string::npos)
                return s.find(suffix, pos + prefix.size()) != string::npos;
        }
        if(prefix.size())
            return s.find(prefix) != string::npos;
        if(suffix.size())
            return s.find(suffix)!= string::npos;
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    cout<<s.hasMatch("luck", "u*");
    
    return EXIT_SUCCESS;
}
