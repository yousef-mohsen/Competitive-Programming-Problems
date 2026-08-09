//
//  main.cpp
//  2125. Number of Laser Beams in a Bank
//
//  Created by Yousef on 29.05.26.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int length = bank.size(), current = 0, previous = 0, sum = 0;
        for(int i = 0; i < length; i++)
        {
            current = count(bank[i].begin(), bank[i].end(), '1');
            
            if(current)
            {
                sum += current * previous;
                previous = current;
            }
        }
        
        return sum;
    }
};


int main(int argc, const char * argv[]) {
    
    vector<string> bank = {"000","111","000"};
    
    Solution s;
    cout<<s.numberOfBeams(bank);
    
    
    return EXIT_SUCCESS;
}
