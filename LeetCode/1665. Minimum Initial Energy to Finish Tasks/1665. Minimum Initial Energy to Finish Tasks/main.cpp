//
//  main.cpp
//  1665. Minimum Initial Energy to Finish Tasks
//
//  Created by Yousef on 28.06.26.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        
        sort(tasks.begin(), tasks.end(),[] (const vector<int>& a, const vector<int>& b)
             
             {
            return a[1]-a[0] > b[1]-b[0];
        });
         
            int initial = tasks[0][1], total = tasks[0][1];
        for(auto &t: tasks)
        {
            if(t[1] > initial)
            {
                total +=t[1] - initial;
                initial += t[1] - initial;
                
            }
            initial -= t[0];
        }
            
        
        return total;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<vector<int>>tasks = {{1,3}};
    cout<<s.minimumEffort(tasks);
    return 0;
}
