//
//  main.cpp
//  60. Permutation Sequence
//
//  Created by Yousef on 24.06.26.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        
        string s;
        for(int i = 1; i <= n; i++)
            s+=to_string(i);
        
        
        for(int i = 1; i < k; i++)
            next_permutation(s.begin(), s.end());
        
        return s;
        
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout<<s.getPermutation(9, 362870);
    return 0;
}
