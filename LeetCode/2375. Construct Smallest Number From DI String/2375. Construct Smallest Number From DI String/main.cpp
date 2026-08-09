//
//  main.cpp
//  2375. Construct Smallest Number From DI String
//
//  Created by Yousef on 30.05.26.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string ans = "";
    int pattern_size = 0;
    vector<bool> taken = vector<bool> (10, false);
    bool found = false;
    string smallestNumber(string pattern) {
     
     pattern_size = pattern.size();
     string temp = "";
     find_permutation(1, pattern, temp);
     
     return ans;
    }
    void find_permutation(int n, string& pattern, string& s)
    {
        if (n == pattern_size + 2)
            {
                if (ans.size() == 0)
                {
                    ans = s;
                    found = true;
                    return;
                }
                
               
            }
            
            for(int i = 1; i <= 9; i++)
            {
                if (found)
                    return;
                if(!taken[i])
                {
                    if(n == 1)
                    {
                        s.push_back(char ('0' + i));
                        
                        taken[i] = true;
                        find_permutation(n + 1, pattern, s);
                        taken[i] = false;
                        s.pop_back();
                    }
                    
                    else{
                        if(pattern[n - 2] == 'I' && i <= s[n - 2] - '0')
                            continue;
                        if(pattern[n - 2] == 'D' && i >= s[n - 2] - '0')
                            continue;
                        
                        s.push_back(char ('0' + i));
                        taken[i] = true;
                        find_permutation(n + 1, pattern, s);
                        taken[i] = false;
                        s.pop_back();
                    }
                }
            }
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.smallestNumber("I");
    return EXIT_SUCCESS;
}
