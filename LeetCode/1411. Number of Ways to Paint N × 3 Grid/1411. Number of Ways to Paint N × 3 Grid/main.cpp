//
//  main.cpp
//  1411. Number of Ways to Paint N × 3 Grid
//
//  Created by Yousef on 02.06.26.
//

#include <iostream>
using namespace std;

class Solution {
public:
    long long mo = 1e9 + 7, ans = 0;
    int numOfWays(int n) {
        if (n == 1)
            return 12;
        else
            solve(6,6,1,n);
        return ans;
    }
    void solve (long long  two_coloured, long long  three_coloured, int depth, int n)
    {
        if(depth == n)
        {
            ans = (two_coloured + three_coloured) % mo;
            return;
        }
            
        
        long long  new_2 = ((two_coloured * 3) % mo + (three_coloured * 2) % mo)%mo;
        long long  new_3 = ((two_coloured * 2) % mo + (three_coloured * 2) % mo)%mo;
        
        solve(new_2,new_3 ,depth + 1,n);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.numOfWays(5000);
    
    return EXIT_SUCCESS;
}
