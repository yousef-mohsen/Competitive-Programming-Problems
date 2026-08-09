//
//  main.cpp
//  4. Median of Two Sorted Arrays
//
//  Created by Yousef on 20.05.26.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> merged;
        int l1 = nums1.size(), l2 = nums2.size();
        int i = 0, k = 0;
        while (i != l1 && k != l2)
        {
            if (nums1[i] < nums2[k])
            {
                merged.push_back(nums1[i]);
                i++;
            }
            else
            {
                merged.push_back(nums2[k]);
                k++;
            }
             
        }
        while(i != l1)
        {
            merged.push_back(nums1[i]);
            i++;
        }
        while (k != l2)
        {
            merged.push_back(nums2[k]);
            k++;
        }
            
        int l = merged.size();
        if (l > 0){
            if (l % 2 == 0)
            {
                return (merged[l/2] + merged[l/2 - 1])/2.0;
            }
            else
            {
                return merged[l/2]/1.0;
            }
        }
        else
            return 0;
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
    vector<int> v1 = {1};
    vector<int> v2 = {1,2,3};
    cout<<s.findMedianSortedArrays(v1, v2);
    
    return EXIT_SUCCESS;
}
