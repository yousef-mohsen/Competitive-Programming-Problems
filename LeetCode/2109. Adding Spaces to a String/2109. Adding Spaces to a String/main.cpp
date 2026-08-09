//
//  main.cpp
//  2109. Adding Spaces to a String
//
//  Created by Yousef on 14.06.26.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int l = s.size(), size = spaces.size();
        string ans = "";
        int counter = 0;
        for (int i = 0; i < l; i ++)
        {
            
            
            if(counter < size && i == spaces[counter])
            {
                ans += " ";
                counter ++;
            }
            ans += s[i];
            
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> test = {1};
    cout<<s.addSpaces("a", test);
    
    return 0;
}
