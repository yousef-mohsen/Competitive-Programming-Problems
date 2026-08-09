//
//  main.cpp
//  686. Repeated String Match
//
//  Created by Yousef on 17.06.26.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        string r = a;
        int a_s = a.size(), b_s = b.size(), d = b_s / a_s + 2;
        
        for(int i = 0; i < d; i++)
            r += a;
        
        
        string z = b + "*" + r;
        
        vector<int> z_v(z.size(), 0);
        int z_s = z_v.size(), left = 0, right = 0, counter = 0, c = 0;
        
        for(int i = 1; i < z_s; i++)
        {
            
            if(i > right)
            {
                counter = 0;
                left = i, right = i, c = 0;
                
                while(right < z_s && z[right] == z[c])
                {
                    right++;
                    c++;
                    counter ++;
                }
                if(right == z_s || z[right] != z[c])
                    right--;
                z_v[i] = counter;
                
            }
            else if(z_v[i - left] + i <= right)
            {
                z_v[i] = z_v[i - left];
            }
            else
            {
                left = i;
                counter = right - i + 1;
                c = counter;
                right ++;
                
                while(right < z_s &&z[right] == z[c])
                {
                    right ++;
                    counter ++;
                    c++;
                }
                if(right == z_s || z[right] != z[c])
                    right--;
                z_v[i] = counter;
                
            }
            if (z_v[i] == b_s)
                break;
            
        }
        
        for(int i = b_s + 1; i < z_s; i ++)
        {
            if(z_v[i] == b_s)
                return (z_v[i] + i - (b_s) + a_s - 2)/a_s;
        }
        
        return -1;
    }
        
        
};


int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.repeatedStringMatch("abc", "abcabc");
    return EXIT_SUCCESS;
}
