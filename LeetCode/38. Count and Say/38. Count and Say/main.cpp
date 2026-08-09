//
//  main.cpp
//  38. Count and Say
//
//  Created by Yousef on 22.06.26.
//

#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        
        if (n == 1)
            return "1";
        
        string s1 = "1", s2 = "";
        
        for(int k = 1; k < n; k++)
        {
            
            int size = s1.size();
            
            while(!empty(s2))
                s2.pop_back();
            
            for(int i = 0; i < size; i++)
            {
                int count = 1;
                int j = i + 1;
                for(; j < size && s1[j] == s1[i]; j++)
                {
                    count++;
                }
                
                
                s2 += to_string(count);
                s2 += s1[i];
                if(count > 1)
                    i = j - 1;
                
            }
            swap(s1, s2);
            
        }
        return s1;
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.countAndSay(5);
    return EXIT_SUCCESS;
}
