//
//  main.cpp
//  3. Longest SubString Without Repeating Characters
//
//  Created by Yousef on 20.05.26.
//

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l_ptr = 0, r_ptr = 0, maximum = 0, current = 0, l = s. size(), pos = 0;
        vector<int> v (1000, -1);
        
        while (r_ptr < l)
            
        {
            //if(m.find(s[r_ptr]) != m.end())
            if(v[int(s[r_ptr]) ] != -1)
            {
                //current = r_ptr - m[s[r_ptr]] ;
                current = r_ptr - v[int(s[r_ptr]) ] ;
                //pos = m[s[r_ptr]];
                pos = v[int(s[r_ptr])];
                
                while(l_ptr <= pos)
                {
                    //m.erase(s[l_ptr]);
                    v[int(s[l_ptr])] = -1;
                    l_ptr++;
                }
                
                //m[s[r_ptr]] = r_ptr;
                v[int(s[r_ptr])] = r_ptr;
                r_ptr += 1;
            }
            else
            {
                //m[s[r_ptr]] = r_ptr;
                v[int(s[r_ptr])] = r_ptr;
                r_ptr += 1;
                current += 1;
            }
            maximum = max(current, maximum);
        }
        
        return maximum;
}
};



int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.lengthOfLongestSubstring("pwwkew");
    //string z =" ";
    //cout<<int(z[0]);
    return EXIT_SUCCESS;
}
