//
//  main.cpp
//  2437. Number of Valid Clock Times
//
//  Created by Yousef on 09.06.26.
//

#include <iostream>
#include <string>

using namespace std;



class Solution {
public:
    int countTime(string time) {
        if(time.find('?') == string::npos)
            return 1;
        
        int count = 1;
        if( time[0] == '?' && time[1] == '?')
            count = 24;
        if(time[0] == '?' && time[1] != '?')
        {
            if(time[1] > '3')
                count = 2;
            else
            {
                count = 3;
                
            }
        }
            
        
        if(time[0] != '?' && time[1] == '?')
        {
            if(time[0] < '2')
                count = 10;
            else
                count = 4;
        }
        if(time[3] == '?')
            count *= 6;
        
        if(time[4] == '?')
            count *= 10;
        
        return count;
        
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
    cout<<s.countTime("0?:0?");

    return 0;
}
