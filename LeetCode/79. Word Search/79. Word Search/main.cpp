//
//  main.cpp
//  79. Word Search
//
//  Created by Yousef on 13.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<bool>> visited;
    bool solved = false;
    int n, m, size;
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size(), size = word.size();
        //visited = vector<vector<bool>> (m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i ++)
            for(int k = 0; k < n; k++)
                if(board[i][k] == word[0])
                    if(solve(board, word, i, k, 0))
                        return true;
        return false;
        
    }
    bool solve (vector<vector<char>>& board, string & word, int i, int k, int length)
    {
        if (length == size - 1 && board[i][k] == word[length])
        {
            solved = true;
            return true;
        }
        if(board[i][k] != word[length])
            return false;
        char temp = board[i][k];
        board[i][k] = '[';
        
        if(i > 0 && !solved)
            solve(board, word, i - 1, k, length + 1);
        
        if(k > 0 && !solved)
            solve(board, word, i, k - 1, length + 1);
        
        if(k + 1 < n && !solved)
            solve(board, word, i, k + 1, length + 1);
        
        if(i + 1 < m && !solved)
            solve(board, word, i + 1, k, length + 1);
        //visited[i][k] = false;
        board[i][k] = temp;
        
        return solved;
        
        
    }
};

using namespace std;
int main(int argc, const char * argv[]) {
    vector<vector<char>> board  = {{'b'}};
    Solution s;
    cout<<s.exist(board, "a");
    return 0;
}
