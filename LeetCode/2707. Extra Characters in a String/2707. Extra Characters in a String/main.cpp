//
//  main.cpp
//  2707. Extra Characters in a String
//
//  Created by Yousef on 15.06.26.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        
        int size = dictionary.size(), counter = 1, s_size = s.size();
        vector<vector<int>> t (51 * size + 1, vector<int>(26, -1));
        vector<bool> v(51 * size + 1, false);
        
        for(auto & s: dictionary)
        {
            int n = 0;
            int w_s = s.size();
            for(int i = 0; i < w_s; i++)
            {
                if(t[n][s[i] - 'a'] == - 1)
                {
                    
                    t[n][s[i] - 'a'] = counter ++;
                    n = counter  - 1;
                }
                else
                {
                    n = t[n][s[i] - 'a'];
                }
            }
            v[n] = 1;
        }
        
        vector<int> visited (s_size + 1);
        for(int i = 0; i <= s_size; i++)
           visited[i] = i ;
        
        
        for(int i = 0; i < s_size; i++)
        {
            int n = 0, k = i;
            if(i > 0)
                visited[i + 1] = min(visited[i + 1], visited[i] + 1);
            while(k < s_size && t[n][s[k] - 'a'] != -1)
            {
                n = t[n][s[k] - 'a'];
                if(v[n])
                {
                    visited[k + 1] = min (visited[k + 1], visited[i]);
                    
                    
                    
                }
                
                k++;
            }
            
        }
        
        return visited[s_size];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    /*
    vector<string> d = {
        "leet","code","leetcode"
    };
    cout<<s.minExtraChar("leetscode", d);
    */
    
    vector<string> d = {
            "yv","bmab","hv","bnsll","mra","jjqf","g","aiyzi","ip","pfctr","flr","ybbcl","biu","ke","lpl","iak","pirua","ilhqd","zdhx","fux","xaw","pdfvt","xf","t","wq","r","cgmud","aokas","xv","jf","cyys","wcaz","rvegf","ysg","xo","uwb","lw","okgk","vbmi","v","mvo","fxyx","ad","e"
        };
        cout<<s.minExtraChar("kevlplxozaizdhxoimmraiakbak", d);
     
    return 0;
}
