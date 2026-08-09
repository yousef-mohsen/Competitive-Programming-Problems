//
//  main.cpp
//  3114. Latest Time You Can Obtain After Replacing Characters
//
//  Created by Yousef on 05.06.26.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    string findLatestTime(string s) {
            if(s.find('?') == string::npos)
                return s;
        if(s[0] == s[1] && s[1] == '?')
            s[0] = s[1] = '0' + 1;
        if(s[0] == '0' && s[1] == '?')
            s[1] = '0' + 9;
        if(s[0] == '1' && s[1] == '?')
            s[1] = '0' + 1;
        if(s[0] == '?' && s[1] != '?')
        {
            if(s[1] > '1')
                s[0] = '0';
            else
                s[0] = '1';
        }
        if(s[3] == '?')
            s[3] = '5';
        if(s[4] == '?')
            s[4] = '9';
        
        
        return s;
     
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.findLatestTime("?1:?6");

    return 0;
}
