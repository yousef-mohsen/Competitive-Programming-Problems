//
//  main.cpp
//  773. Sliding Puzzle
//
//  Created by Yousef on 28.06.26.
//

#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int n = INT_MAX;
    string target= "123450";
    unordered_map<string, int> m;
    int slidingPuzzle(vector<vector<int>>& board) {
        
        string state = "";
        for (auto row: board)
            for(auto x: row)
                state+= char('0' + x);
        
        solve(0, state);
        if(n == INT_MAX)
            return -1;
        return n;
    }
    void solve(int moves, string& state)
    {
        if(state == target)
        {
            n = min (n, moves);
            return;
        }
        if(m.find(state) != m.end() && moves > m[state])
        {
            return;
        }
        m[state] = moves;
        
        
        if(state[0] == '0')
        {
            swap(state[0], state[1]);
            solve(moves + 1, state);
            swap(state[0], state[1]);
            
            swap(state[0], state[3]);
            solve(moves + 1, state);
            swap(state[0], state[3]);
        }
        if(state[1] == '0')
        {
            swap(state[0], state[1]);
            solve(moves + 1, state);
            swap(state[0], state[1]);
            
            swap(state[1], state[2]);
            solve(moves + 1, state);
            swap(state[1], state[2]);
            
            swap(state[1], state[4]);
            solve(moves + 1, state);
            swap(state[1], state[4]);
        }
        
        if(state[2] == '0')
        {
            swap(state[1], state[2]);
            solve(moves + 1, state);
            swap(state[1], state[2]);
            
            swap(state[2], state[5]);
            solve(moves + 1, state);
            swap(state[2], state[5]);
            
        }
        
        if(state[3] == '0')
        {
            swap(state[0], state[3]);
            solve(moves + 1, state);
            swap(state[0], state[3]);
            
            swap(state[3], state[4]);
            solve(moves + 1, state);
            swap(state[3], state[4]);
            
        }
        
        if(state[4] == '0')
        {
            swap(state[1], state[4]);
            solve(moves + 1, state);
            swap(state[1], state[4]);
            
            swap(state[3], state[4]);
            solve(moves + 1, state);
            swap(state[3], state[4]);
            
            swap(state[4], state[5]);
            solve(moves + 1, state);
            swap(state[4], state[5]);
        }
        
        if(state[5] == '0')
        {
            swap(state[2], state[5]);
            solve(moves + 1, state);
            swap(state[2], state[5]);
            
            swap(state[5], state[4]);
            solve(moves + 1, state);
            swap(state[5], state[4]);

        }
        
        
    }
};


int main(int argc, const char * argv[]) {
    vector<vector<int>> test = {{}};
    Solution s;
    cout<<s.slidingPuzzle(test);
    return 0;
}
