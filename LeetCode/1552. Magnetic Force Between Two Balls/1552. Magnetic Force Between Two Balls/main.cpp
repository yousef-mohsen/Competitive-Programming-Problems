//
//  main.cpp
//  1552. Magnetic Force Between Two Balls
//
//  Created by Yousef on 08.08.26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int l;
    int maxDistance(vector<int> &position, int m) {

        int maxi = 0;
        l = position.size();
        sort(position.begin(), position.end());
        
        maxi = position[l - 1];
        
        int x = 0;
        
        for (int i = maxi; i >= 1; i /= 2) {
            while (solvable(i + x, position, m)) {
                x += i;
            }
        }

        return x;
    }
    bool solvable(int d, vector<int> &position, int m) {
        int count = 1, pos = 0;
        for (int i = 1; i < l; i++) {
            if (position[i] - position[pos] >= d) {
                count++;
                pos = i;
            }
            if (count >= m)
                return true;
        }
        return false;
    }
};
int main(int argc, const char *argv[]) {
    Solution s;
    vector<int> t = {1,2,3,4,7};
    
    s.maxDistance(t, 3);
}
