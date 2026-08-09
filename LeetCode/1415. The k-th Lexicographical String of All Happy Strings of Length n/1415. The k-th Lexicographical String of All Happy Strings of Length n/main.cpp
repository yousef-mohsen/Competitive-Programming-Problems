//
//  main.cpp
//  1415. The k-th Lexicographical String of All Happy Strings of Length n
//
//  Created by Yousef on 28.05.26.
//

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    vector<char> characters= {'a', 'b', 'c'};
    vector<string> ans;
    int counter = 0;
    string getHappyString(int n, int k) {
        string s = "";
        get_permutation(0, n, k, s);
        
        if (ans.size() >= 1)
            return ans[0];
        else
            return "";
        
        
    }
    
    void get_permutation(int i, int n, int k, string &s){
        
        if(i == n)
        {
            counter ++;
            if (counter == k)
                ans.push_back(s);
            return;
        }
        for(const auto & c: characters)
        {
            if(ans.size() >= 1)
                return;
            if(i >= 1)
            {
                if(s[i - 1] == c)
                    continue;
            }
            s.push_back(c);
            get_permutation(i + 1, n, k, s);
            s.pop_back();
            
        }
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.getHappyString(3, 9);
    return EXIT_SUCCESS;
}
