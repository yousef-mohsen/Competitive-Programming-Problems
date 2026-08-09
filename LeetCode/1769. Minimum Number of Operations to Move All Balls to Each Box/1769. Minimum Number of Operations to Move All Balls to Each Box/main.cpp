//
//  main.cpp
//  1769. Minimum Number of Operations to Move All Balls to Each Box
//
//  Created by Yousef on 28.05.26.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int length = boxes.size();
        vector<int> to_left(length, 0);
        vector<int> to_right(length, 0);
        vector<int> ans (length, 0);
        int sum = boxes[0] - '0';
        for(int i = 1; i < length ; i++)
        {
            to_right[i] = to_right[i - 1] + sum;
            sum += boxes[i] - '0';
        }
        sum = boxes[length - 1] - '0';
        
        for(int i = length - 2; i >= 0 ; i--)
        {
            to_left[i] = to_left[i + 1] + sum;
            sum += boxes[i] - '0';
        }
        
        for(int i = 0; i < length; i ++)
        {
            ans[i] = to_left[i] + to_right[i];
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    s.minOperations("11");
    return EXIT_SUCCESS;
}
