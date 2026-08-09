//
//  main.cpp
//  67. Add Binary
//
//  Created by Yousef on 24.05.26.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size())
            swap(a,b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        
        bool carry = false;
        int first_digit = 0, second_digit = 0;
        for (int i = 0; i < b.size(); i++)
        {
            first_digit = a[i] - 48;
            second_digit = b[i] - 48;
            
            a[i] = first_digit ^ second_digit ^ carry + '0';
            carry = first_digit & carry ||  second_digit & carry || first_digit & second_digit;

        }
        for(int i = b.size(); i < a.size(); i++)
        {
            first_digit = a[i] - 48;
            a[i] = first_digit ^ carry + '0';
            carry = first_digit & carry ;
        }
       
        
        if(carry)
            a += to_string(carry);
        
        reverse(a.begin(), a.end());
        
        return a;
        
    }
};

int main(int argc, const char * argv[]) {
    string a = "11";
    string b = "1";
    Solution s;
    cout<<s.addBinary(a, b);

    return EXIT_SUCCESS;
}
