//
//  main.cpp
//  1944. Number of Visible People in a Queue
//
//  Created by Yousef on 24.06.26.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int l = heights.size();
        vector<int> ans(l, 0);
        stack<int> s;
        
        for(int i = l - 1; i >= 0; i--)
        {
            if(s.empty())
            {
                s.push(heights[i]);
                continue;
            }
            int counter = 0;
            while(!s.empty() && heights[i] > s.top())
            {
                counter ++;
                s.pop();
            }
            if(!s.empty())
                counter++;
            ans[i] = counter;
            s.push(heights[i]);
            
        }
        
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> heights = {1};
    s.canSeePersonsCount(heights);
    return 0;
}
 
