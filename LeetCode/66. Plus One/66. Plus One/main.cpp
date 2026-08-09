//
//  main.cpp
//  66. Plus One
//
//  Created by Yousef on 09.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1, length = digits.size();
        for(int i = length - 1; i >=0; i --)
            
        {
            if( digits [i] + carry > 9)
            {
                if(i == 0)
                {
                    digits[0] = 0;
                    vector<int> ans (length + 1, 0);
                    ans[0] = 1;
                    for(int j = 0; j < length; j ++)
                        ans[j + 1] = digits[j];
                    
                    return ans;
                }
                carry = 1;
                digits[i] = 0;
            }
            else
            {
                digits[i] += carry;
                return digits;
            }
        }
        
        return digits;
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> test = {8,9,9,9};
    s.plusOne(test);
    return 0;
}
