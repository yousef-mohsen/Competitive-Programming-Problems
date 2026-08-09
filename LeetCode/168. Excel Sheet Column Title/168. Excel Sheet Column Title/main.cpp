//
//  main.cpp
//  168. Excel Sheet Column Title
//
//  Created by Yousef on 10.06.26.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        int mo, pow = 1;
        
        
        while(columnNumber)
        {
            columnNumber /= pow;
            mo = columnNumber % 26;
            if(mo == 0)
            {
                ans += 'Z';
                columnNumber -= 26;
            }
            else
                ans+= 'A' + mo - 1;
            
            columnNumber -= mo;
            pow = 26;
                
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.convertToTitle(2056);
    return 0;
}
