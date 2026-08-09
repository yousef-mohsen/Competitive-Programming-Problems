//
//  main.cpp
//  2391. Minimum Amount of Time to Collect Garbage
//
//  Created by Yousef on 30.05.26.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int sum = 0;
        int count = 0, glass_dist = 0, metal_dist = 0, paper_dist = 0, length = garbage.size(), temp = 0;
        
        for (int i =0; i < length; i++)
        {
            if (i != 0)
            {
                sum += travel[i - 1];
                bool g = false, p = false, m = false;
                for(auto c: garbage[i])
                {
                    if(g && p && m)
                        break;
                    if(c == 'P')
                    {
                        p = true;
                        paper_dist = sum;
                        
                    }
                    if(c == 'G')
                    {
                        g = true;
                        glass_dist = sum;
                        
                    }
                    if(c == 'M')
                    {
                        m = true;
                        metal_dist = sum;
                        
                    }
                }
            }
            count += garbage[i].size();
        }
        
        
        return count + glass_dist + paper_dist + metal_dist;
        
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
