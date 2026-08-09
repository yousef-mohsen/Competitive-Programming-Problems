//
//  main.cpp
//  2785. Sort Vowels in a String
//
//  Created by Yousef on 30.05.26.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        int length = s.size();
        vector<bool> is_vowel(60, false);
        string vowels = "AEIOUaeiou";
        vector<int> count(60, 0);
        
        for(auto a: vowels)
            is_vowel[a - 'A'] = true;
        
        for(auto a: s)
            count[a - 'A'] ++;
        
        
        int pos = 0;
        
        for (int i = 0; i < length; i++)
        {
            if(!is_vowel[s[i] - 'A'])
                continue;
            
            while (count[vowels[pos] - 'A'] == 0)
                pos ++;
                
            s[i] = vowels[pos];
            count[vowels[pos] - 'A'] --;
            
        }
        return s;
        
        
    }
};
 

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.sortVowels("lEetcOde");
    
    
    return 0;
}
