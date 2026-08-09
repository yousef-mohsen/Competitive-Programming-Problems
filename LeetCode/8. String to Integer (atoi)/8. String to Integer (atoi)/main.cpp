//
//  main.cpp
//  8. String to Integer (atoi)
//
//  Created by Yousef on 26.05.26.
//

#include <iostream>
#include <string>
#include <limits>

using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        
        s.erase(0, s.find_first_not_of(' '));
        bool negative = false;
        negative = s[0] == '-';
        
        int start = 0;
        
        if(s[0] == '-' || s[0] == '+')
            //s.erase(0,1);
            start ++;
        int pos = -1;
        
        for(int i = start; i < s.size(); i++)
        {
            if(!isdigit(s[i]))
            {
                pos = i;
                break;
            }
        }
        if(pos != -1)
            s.erase(pos, s.size());
        
        //s.erase(0, s.find_first_not_of('0'));
        while(s[start] == '0')
            start++;
        
        
        if(start == s.size())
        {
            return 0;
        }
        
        if(s.size() - start > 10)
        {
            if(negative)
                return INT_MIN;
            else
                return INT_MAX;
        }
        
        
        
        int sum = 0;
        for(int i = start; i < s.size(); i ++)
        {
            if(sum > (INT_MAX/ 10) || ((sum == INT_MAX / 10) && s[i] - '0' > 7))
                {
                    return INT_MAX;
                }
            
            if((sum < INT_MIN/10) || ((sum == INT_MIN / 10) && s[i] - '0' == 9))
                    return INT_MIN;
            
            
            sum *= 10;
            if(negative)
                sum-= (s[i]-'0');
            else
                sum += (s[i]-'0');
                
        }
        
        return sum;
        
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.myAtoi("-2147483649");
    
    return EXIT_SUCCESS;
}
