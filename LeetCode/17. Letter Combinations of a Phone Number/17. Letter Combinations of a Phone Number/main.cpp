//
//  main.cpp
//  17. Letter Combinations of a Phone Number
//
//  Created by Yousef on 11.06.26.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> ans;
    int counter = 0;
    vector<string> letterCombinations(string digits) {
        vector<vector<int>> v (10, vector<int>());
        v[2] = {'a','b','c'};
        v[3] = {'d','e','f'};
        v[4] = {'g','h','i'};
        v[5] = {'j','k','l'};
        v[6] = {'m','n','o'};
        v[7] = {'p','q','r', 's'};
        v[8] = {'t','u','v',};
        v[9] = {'w','x','y','z'};
        
        int size = 0, length = digits.size();
        
        size = v[digits[0] - '0'].size();
        for(int i = 1; i < length; i ++)
        {
            size *= v[digits[i] - '0'].size();
        }
        
        ans = vector<string> (size,"");
        string s = "";
        solve(0,length, s, v, digits);
        return ans;
    }
    void solve(int n, int length, string& s, vector<vector<int>> &v, string& digits)
    {
        if(n == length)
        {
            ans[counter ++] = s;
            return;
        }
        int number = digits[n] - '0';
        int size = v[number].size();
        for(int i = 0; i < size; i ++)
        {
            s.push_back(v[number][i]);
            solve(n + 1, length, s, v, digits);
            s.pop_back();
            
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    s.letterCombinations("2");
    cout<<"test";
    return EXIT_SUCCESS;
}
