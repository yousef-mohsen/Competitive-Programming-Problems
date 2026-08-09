//
//  main.cpp
//  100. Same Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr)
            return false;
        if (q == nullptr)
            return false;
        
        return dfs(p, q);
    }
    bool dfs(TreeNode* p, TreeNode* q)
    {
        if(p->val != q ->val)
            return false;
        if((p->left == nullptr && q ->left != nullptr) || (p->left != nullptr && q -> left== nullptr))
            return false;
        if((p->right == nullptr && q ->right != nullptr) || (p->right != nullptr && q -> right == nullptr))
            return false;
        bool left = true, right = true;
        
        if(p->left != nullptr)
            left = dfs(p->left, q->left);
        if(p->right != nullptr)
            right = dfs(p->right, q->right);
        
        return left && right;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return EXIT_SUCCESS;
}
