//
//  main.cpp
//  914. X of a Kind in a Deck of Cards
//
//  Created by Yousef on 04.06.26.
//

#include <iostream>
#include <unordered_map>
#include <climits>
#include <numeric>

using namespace std;


class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        
        for (auto d: deck)
            m[d] ++;
        
        int g = m.begin()->second;
        
        for (auto &k: m)
        {
            g = gcd(g, k.second);
        }
            
        
        if (g == 1)
            return false;
        
        
        return true;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
