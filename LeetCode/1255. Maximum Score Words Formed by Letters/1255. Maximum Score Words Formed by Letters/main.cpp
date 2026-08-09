//
//  main.cpp
//  1255. Maximum Score Words Formed by Letters
//
//  Created by Yousef on 01.06.26.
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        int words_size = words.size(), letters_size = letters.size();
        vector<int> freq (26, 0);
        vector<int> values(words_size, 0);
        
        for (auto& l : letters)
        {
            freq[l - 'a'] ++;
        }
        for (int i = 0; i < words_size; i ++)
        {
            int value = 0;
                for (auto l: words[i])
                {
                    value += score[l - 'a'];
                }
            values [i] = value;
        }
        
        int maximum = 0, end = 1<<words_size, sum = 0;
        vector<int> freq_copy (26, 0);
        
        for (int i = 0; i < end; i ++)
        {
            
            freq_copy = freq;
            sum = 0;
            for(int k = 0; k < words_size; k++)
            {
                
                if(i & (1<<k))
                {
                    if(can_be_formed(words[k], freq_copy))
                    {
                        sum += values[k];
                    }
                    else
                    {
                        sum = INT_MIN;
                        break;
                    }
                }
                maximum = max(sum, maximum);
            }
        }
        
        return maximum;
        
    }
    bool can_be_formed(string& word ,vector<int>& freq)
    {
        for(auto l: word)
        {
            if(!freq[l - 'a'])
                return false;
            else
            {
                freq[l - 'a'] --;
            }
        }
        return true;
    }
    
};


int main(int argc, const char * argv[]) {
    vector<string> words = {"dog","cat","dad","good"};
    vector<char> letters = {'a','a','c','d','d','d','g','o','o'};
    vector<int> score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    
    Solution s;
    cout<<s.maxScoreWords(words, letters, score);
    return 0;
}
