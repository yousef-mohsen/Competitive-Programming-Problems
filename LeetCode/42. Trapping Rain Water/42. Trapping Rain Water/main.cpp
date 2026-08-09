//
//  main.cpp
//  42. Trapping Rain Water
//
//  Created by Yousef on 24.06.26.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<pair<int, int>> s;
        
        int size = height .size();
        pair<int, int> mx = {-1, -1};
        
        vector<int> next (size, -1);
        
        for(int i = size - 1; i >= 0; i--)
        {
            
            if(s.empty())
            {
                s.push({height[i], i});
                next[i] = mx.second;
                
                if(mx.first < height[i])
                {
                    mx.first = height[i];
                    mx.second = i;
                }
                continue;
            }
            while(!s.empty() && height[i] > s.top().first)
            {
                s.pop();
            }
            if(s.empty())
            {
                next[i] = mx.second;
            }
            else
            {
                next[i] = s.top().second;
            }
            s.push({height[i], i});
            if(mx.first < height[i])
            {
                mx.first = height[i];
                mx.second = i;
            }
            
        }
        
        
        /*
        for(int i = 0; i < size; i++)
        {
            if(s.size() == 0)
            {
                s.push({height[i], i});
                continue;
            }
            auto p = s.top();
            while(height[i] >= p.first)
            {
                next[p.second] = i;
                s.pop();
                if(!s.empty())
                {p = s.top();}
                else
                    break;
            }
            s.push({height[i], i});
        }*/
        
        int sum = 0, m, n;
        for(int i = 0; i < size; i ++)
        {
            if (next[i] == -1 || height[i] == 0)
                continue;
            n = next[i];
            m = min(height[i], height[next[i]]);
            i ++;
            while(i < size && i!= n)
            {
                sum += m - height[i];
                i++;
            }
            i--;
        }
        return sum;
    }
    
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> test = {13,2,10,12};
    cout<<s.trap(test);

    return 0;
}
