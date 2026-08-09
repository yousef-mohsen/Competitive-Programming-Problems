//
//  main.cpp
//  258. Add Digits
//
//  Created by Yousef on 12.06.26.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        
        if(num < 10)
            return num;
        if(num % 9 == 0)
            return 9;
            
        return num % 9;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    
    for (int i = 0; i < 5000; i++)
       cout<<i<<": "<<s.addDigits(i)<<"\n";
    //cout<,s.addDigits(10)<<"\n";
    return 0;
}
