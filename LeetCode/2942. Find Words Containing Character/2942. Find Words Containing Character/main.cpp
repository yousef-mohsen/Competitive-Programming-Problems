//
//  main.cpp
//  2942. Find Words Containing Character
//
//  Created by Yousef on 27.05.26.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        
        for(int i = 0; i < words.size(); i ++)
            if(words[i].find(x) != string::npos)
                ans.push_back(i);

        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
