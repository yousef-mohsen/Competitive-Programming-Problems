//
//  main.cpp
//  124. Binary Tree Maximum Path Sum
//
//  Created by Yousef on 27.06.26.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int mx_r = -2000;
    int maxPathSum(TreeNode* root) {
        
        dfs(root);
        return mx_r;
        
    }
    int dfs(TreeNode* r)
    {
        mx_r = max(mx_r, r->val);
        int left = INT_MIN, right = INT_MIN, mx = INT_MIN;
        
        if(r->left != nullptr)
        {
            left = dfs(r->left);
            mx = max(mx, left);
        }
        if(r->right != nullptr)
        {
            right = dfs(r->right);
            mx = max(mx, right);
        }
        if(r->left == nullptr && r->right == nullptr)
            return r->val;
        
        if(right > 0 && left > 0)
            mx_r = max(mx_r,r->val + left + right);
        
        mx_r = max(mx_r, r->val + mx);
        
        return max(r->val, r->val + max(right, left));
    }
};
int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    

    Solution sol;
    cout << sol.maxPathSum(root) << endl;  // Expected: 6
    return 0;
}
