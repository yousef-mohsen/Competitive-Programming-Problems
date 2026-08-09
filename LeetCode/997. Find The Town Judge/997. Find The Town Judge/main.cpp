//
//  main.cpp
//  997. Find The Town Judge
//
//  Created by Yousef on 21.05.26.
//

#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> i_trust (n + 1, 0);
        vector<int> trusted_from (n + 1, 0);
        
        for (auto t: trust)
        {
            
            i_trust[t[0]] ++;
            trusted_from[t[1]]++;
        }
        
        int counter = 0, pos = 0;
        for(int i = 1; i <= n; i++)
        {
            if(i_trust[i] == 0 && trusted_from[i] == n - 1)
            {
                counter ++;
                pos = i;
            }
        }
        
        if (counter == 1)
        {
            return pos;
        }
        else
        {
            return - 1;
        }
        
    }
};

int main(int argc, const char * argv[]) {
    return EXIT_SUCCESS;
}
