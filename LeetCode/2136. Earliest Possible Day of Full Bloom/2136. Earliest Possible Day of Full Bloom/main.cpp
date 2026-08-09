//
//  main.cpp
//  2136. Earliest Possible Day of Full Bloom
//
//  Created by Yousef on 29.06.26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int size = growTime.size(), last, current = -1, m = 0;
        vector<pair<int,int>> v (size);
        
        for(int i = 0; i < size; i++)
        {
            v[i] = {growTime[i], i};
        }
        sort(v.begin(), v.end(), [](const pair<int, int> & a, const pair<int, int> & b){
            return a.first > b.first;
        });
        
        for(int i = 0; i < size; i++)
        {
            current += plantTime[v[i].second];
            m = max(m,max(current, current + growTime[v[i].second] + 1));
            
        }
        
        return m;
    }
};




int main(int argc, const char * argv[]) {
    vector<int> g = {2};
    vector<int> p = {1};
    Solution s;
    cout<<s.earliestFullBloom(p, g);
    return 0;
}
