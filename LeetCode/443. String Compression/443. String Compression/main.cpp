//
//  main.cpp
//  443. String Compression
//
//  Created by Yousef on 14.06.26.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int length = chars.size();
        
        if(length == 1)
            return 1;
        int index = 0, left = 0, right = 1;
        
        for(int i = 0; right < length; i++)
        {
            while (right < length && chars[right] == chars[left])
                right ++;
            int l = right - left;
            
            chars[index] = chars[left];
            index ++;
            if(l > 1)
            {
                string s = to_string(l);
                int s_s = s.size();
                for(int i = 0; i < s_s; i++)
                {
                    chars[index++] = s[i];
                    
                }
                
            }
            left = right;
        }
        return index;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    vector<char> v = {'a','a','a','b','b','a','a'};
    cout<<s.compress(v);
    return 0;
}
