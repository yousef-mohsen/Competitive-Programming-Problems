//
//  main.cpp
//  2047. Number of Valid Words in a Sentence
//
//  Created by Yousef on 28.05.26.
//

#include <iostream>
#include<string>
#include<sstream>

using namespace std;


class Solution {
public:
    int countValidWords(string sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;
        
        while(ss>>word)
            words.push_back(word);
        int counter = 0;
        
        for (const auto& w: words)
        {
            if (isValid(w))
                counter ++;
        }
        return counter;
    }
    
    bool isValid(const string  & w){
            
            int count  = 0;
        
            for(int i = 0; i < w.size(); i++)
            {
                if(w[i] == '-')
                    count++;
                    
                if(w[i] == '-' && count == 2)
                    return false;
                    
                if(isdigit(w[i]) || (ispunct(w[i]) && w[i]!='-'  && i != w.size()-1))
                return false;
                
                if(w[i] =='-' && (i == 0 || i == w.size() - 1))
                    return false;
                    
                if(w[i] == '-' &&    (!isalpha(w[i - 1]) || ! isalpha(w[i + 1])))
                    return false;
                
            }
            return true;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
