//
//  main.cpp
//  3582. Generate Tag for Video Caption
//
//  Created by Yousef on 28.05.26.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;


class Solution {
public:
    string generateTag(string caption) {
        
        string ans = "#";
        bool first_letter = true;
        int pos = 0, length = caption.size(), word_number = 0, letter_number = 1;
        while (pos < length && letter_number < 100)
        {
            if(caption[pos] == ' '){
                while(pos < length && caption[pos] == ' '){
                    pos ++;
                }
                
             
            }
            word_number ++;
            first_letter = true;
            while(pos < length && caption[pos] != ' ' && letter_number < 100)
            {
                if (first_letter)
                {
                    
                    if(word_number == 1)
                    {
                        ans+= tolower(caption[pos]);
                    }
                    else
                    {
                        ans+= toupper(caption[pos]);
                        
                    }
                    first_letter = false;
                    
                }
                else
                {
                    ans+= tolower(caption[pos]);
                }
                letter_number ++;
                pos++;
                
            }
            
        }
        
        return ans;
    }
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.generateTag("hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh");
    

    return EXIT_SUCCESS;
}
