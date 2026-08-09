//
//  main.cpp
//  1079. Letter Tile Possibilities
//
//  Created by Yousef on 30.05.26.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int ans  = 0, length = 0;
    vector<int> count = vector<int> (26, 0);
    unordered_map <int, int> m;
    int numTilePossibilities(string tiles) {
    
        length = tiles.size();
        for(auto c: tiles)
        {
            m[c - 'A'] ++;
        }
        
        solve(0);
        return ans;
    }
    
    void solve(int n)
    {
        if (n == length)
            return;
        
        for(auto& c: m)
        {
            if(!c.second)
                continue;
            
            ans ++;
            c.second --;
            solve(n + 1);
            c.second ++;
        }
        
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.numTilePossibilities("YYXBTSR");
}
