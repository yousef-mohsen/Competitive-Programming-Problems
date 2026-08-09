//
//  main.cpp
//  771. Jewels and Stones
//
//  Created by Yousef on 27.05.26.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        vector<int> v ('z'-'A' + 1, 0);
        for(auto s: stones)
            v[s - 'A'] ++;
            
        int ans = 0;
        for(auto& j: jewels)
            ans += v[j - 'A'];
            
        return ans;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
