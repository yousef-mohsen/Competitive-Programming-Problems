//
//  main.cpp
//  3756. Concatenate Non-Zero Digits and Multiply by Sum II
//
//  Created by Yousef on 31.05.26.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//
//  main.cpp
//  3756. Concatenate Non-Zero Digits and Multiply by Sum II
//
//  Created by Yousef on 31.05.26.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int length = s.size(), q_length = queries.size();
        
        long long mo = 1e9 + 7;
        
        vector<long long> sum (length, 0);
        vector<long long> power (length + 1, 0);
        vector<long long> digits (length, 0);
        vector<int> ans (q_length, 0);
        vector<long long> no_digits (length, 0);
       
        power[0] = 1;
        for (int i = 1; i <= length; i++)
        {
            power[i] = power[i - 1] * 10;
            power[i] %= mo;
            
        }
        
        
        sum[0] = s[0] - '0';
        long long counter = 0, po = 10;
        if(s[0] - '0' > 0)
        {
            digits[0] = (s[0] - '0');
            counter ++;
            no_digits[0] = counter;
        }
        
        
        for(int i = 1; i < length; i++)
        {
            sum[i] = s[i] - '0';
            sum[i] += sum[i - 1];
            sum[i] = sum[i] % mo;
            if(s[i] - '0' == 0)
            {
                digits[i] = digits[i-1];
                no_digits[i] = counter;
             
            }
            else
            {
                
                if (!counter)
                {
                    digits[i] = (s[i] - '0');
                    no_digits[i] = counter + 1;
                }
                else{
                    digits[i] = (digits[i-1]) * po + (s[i] - '0');
                    no_digits[i] = counter + 1;
                    
                }
                
                digits[i] %= mo;
                counter ++;
                
            }
        }
        
        for (int i= 0; i < q_length; i++)
        {
            int a = queries[i][0];
            int b = queries[i][1];
            
            if(a == 0)
                ans [i] = (digits[b]* sum[b]) % mo;
            else
            {
                long long cnt = no_digits[b] - no_digits[a - 1];

                long long x = digits[b] - digits[a - 1] * power[cnt] % mo;
                x = (x + mo) % mo;

                long long ssum = sum[b] - sum[a - 1];
                ssum = (ssum + mo) % mo;

                ans[i] = (x * ssum) % mo;
            }
            
        }
        
        
        
         return ans;
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
     //(1);
    vector<vector<int>> queries = {{7,9}};
    /*{
        {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5},
        {1,1}, {1,2}, {1,3}, {1,4}, {1,5},
        {2,2}, {2,3}, {2,4}, {2,5},
        {3,3}, {3,4}, {3,5},
        {4,4}, {4,5},
        {5,5}
    };*/
     
    //vector<vector<int>> queries = {{0,7},{1,3},{4,6}};
    //queries[0] = {0,0};
    s.sumAndMultiply("2711785625", queries);
    return 0;
}


int main(int argc, const char * argv[]) {

    Solution s;
     //(1);
    vector<vector<int>> queries = {{8,9}};
    /*{
        {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {0,5},
        {1,1}, {1,2}, {1,3}, {1,4}, {1,5},
        {2,2}, {2,3}, {2,4}, {2,5},
        {3,3}, {3,4}, {3,5},
        {4,4}, {4,5},
        {5,5}
    };*/
     
    //vector<vector<int>> queries = {{0,7},{1,3},{4,6}};
    //queries[0] = {0,0};
    s.sumAndMultiply("2711785625", queries);
    return 0;
}
