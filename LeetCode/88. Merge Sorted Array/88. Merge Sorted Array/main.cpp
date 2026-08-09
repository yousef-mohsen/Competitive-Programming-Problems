//
//  main.cpp
//  88. Merge Sorted Array
//
//  Created by Yousef on 19.05.26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int nums1_ptr = m - 1, nums2_ptr = n - 1, tail = n + m - 1;
        
        while(nums2_ptr >= 0 && nums1_ptr >= 0)
        {
            if (nums2[nums2_ptr] > nums1[nums1_ptr])
            {
                nums1[tail] = nums2[nums2_ptr];
                nums2_ptr --;
            }
            else
            {
                nums1[tail] = nums1[nums1_ptr];
                nums1_ptr --;
            }
            tail--;
        }
        while(nums2_ptr >= 0)
        {
            nums1[tail] = nums2[nums2_ptr];
            nums2_ptr --;
            tail--;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;

        vector<int> nums1 = {4,5,6,0,0,0};
        vector<int> nums2 = {1,2,3};

        int m = 3;
        int n = 3;

        sol.merge(nums1, m, nums2, n);

        cout << "Merged array: ";

        for (int num : nums1)
        {
            cout << num << " ";
        }

        cout << endl;
    return EXIT_SUCCESS;
}
