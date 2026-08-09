//
//  main.cpp
//  112. Path Sum
//
//  Created by Yousef on 09.06.26.
//

#include <iostream>

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        return dfs(root, root->val, targetSum);
    }
    bool dfs(TreeNode* n, int sum, int & targetSum)
    {
        if (!n->left && ! n->right && sum == targetSum)
        {
            return true;
        }
        bool ans = false;
        if(n->left)
            ans = ans || dfs(n->left, sum + n->left->val, targetSum);
        if(n->right)
            ans = ans || dfs(n->right, sum + n->right->val, targetSum);
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
