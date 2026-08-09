//
//  main.cpp
//  3110. Score of a String
//
//  Created by Yousef on 27.05.26.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for(int i = 0; i < s.size() - 1; i++)
            score += max(s[i], s[i + 1]) - min(s[i], s[i + 1]);
            
        return score;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
