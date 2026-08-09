//
//  main.cpp
//  97. Interleaving String
//
//  Created by Yousef on 13.06.26.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int l1, l2, l3;
    vector<vector<bool>> v;
    bool isInterleave(string s1, string s2, string s3) {
        
        l1= s1.size(), l2 = s2.size(), l3 = s3.size();
        
        v = vector<vector<bool>> (l1 + 1 , vector<bool>(l2 + 1, false));
        if (l1 + l2 != l3)
            return false;
        vector<int> count_3 ('z' - 'a' + 1, 0);
        vector<int> count_1_2 ('z' - 'a' + 1, 0);
        
        
        for(int i = 0; i < l3; i++)
            count_3[s3[i] - 'a'] ++;
        
        for(int i = 0; i < l1; i++)
            count_1_2[s1[i] - 'a'] ++;
        
        for(int i = 0; i < l2; i++)
            count_1_2[s2[i] - 'a'] ++;
        
        int c3 = count_3.size();
        for(int i = 0; i < c3; i++)
        {
            if(count_3[i] != count_1_2[i])
                return false;
        }
    
        return solve(0, 0, 0, s1, s2, s3);
    }
    
    bool solve(int i, int j, int k, string& s1, string& s2, string& s3)
    {
        if(i == l1  && j == l2)
            return true;
        
        if(v[i][j])
           return false;
        v[i][j] = true;
        
        if(i < l1 && s1[i] == s3[k]){
            
            if(solve(i + 1, j, k + 1, s1, s2, s3))
                return true;
        }
        
        if(j < l2 && s2[j] == s3[k]){
            
            if(solve(i, j + 1, k + 1, s1, s2, s3))
                return true;
        }
        
        return false;
        
        
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    s.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    return 0;
}
