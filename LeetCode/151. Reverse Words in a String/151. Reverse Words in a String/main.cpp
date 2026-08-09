//
//  main.cpp
//  151. Reverse Words in a String
//
//  Created by Yousef on 14.06.26.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss (s);
        string word = "";
        string ans = "";
        int count = 0;
        vector<string> v;
        
        while(ss>>word)
        {
            v.push_back(word);
        }
        
        int length = v.size();
        
        
        for(int i = length - 1; i >=0; i--)
        {
            if(i == 0)
                ans += v[i];
            else
                ans += v[i] + " ";
            
        }
        return ans;
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.reverseWords("EPY2giL");

    return 0;
}
