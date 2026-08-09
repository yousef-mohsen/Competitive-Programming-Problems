//
//  main.cpp
//  925. Long Pressed Name
//
//  Created by Yousef on 05.06.26.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        
        int ptr = 0, length_n = name.size(), length_t = typed.size();
        
        for(int i = 0; i < length_t; i++)
        {
            if(typed[i] == name[ptr])
            {
                ptr++;
                if (ptr == length_n)
                {
                    for(int k = i + 1; k < length_t; k++)
                    {
                        if(typed[k] != typed[i])
                            return false;
                    }
                    return true;
                }
                    
                continue;
            }
            if(i > 0 && ptr > 0 && typed[i] == typed[i - 1] && typed[i] == name[ptr-1])
                continue;
            
            if(typed[i] != name[ptr])
            {
                return false;
            }
            
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.isLongPressedName("alex", "aaleexa");
    
    return 0;
}
