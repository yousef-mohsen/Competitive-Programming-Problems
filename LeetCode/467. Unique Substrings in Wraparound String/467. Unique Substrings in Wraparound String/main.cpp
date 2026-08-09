//
//  main.cpp
//  467. Unique Substrings in Wraparound String
//
//  Created by Yousef on 19.06.26.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        
        int size = s.size();
        vector<int> m ('z' - 'a' + 1, 0);
        //vector<int> v (size, 1);
        
        
        m[s[size - 1] - 'a'] = 1;
        int counter = 1;
        
        for(int i = size - 2; i >= 0; i--)
        {
            
                if ((s[i] == 'z' && s[i + 1] == 'a') || (s[i] - s[i + 1] == -1) ) {
                    
                    //v[i] += v[i + 1];
                    counter ++;
                    m[s[i] - 'a'] = max(m[s[i] - 'a'], counter);
                }
                else{
                    m[s[i] - 'a'] = max(m[s[i] - 'a'], 1);
                    counter = 1;
                }
            
        }
        int sum = 0;
        for(auto n: m)
            sum +=n;
        
        return sum;
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.findSubstringInWraproundString("cac");

    return 0;
}
