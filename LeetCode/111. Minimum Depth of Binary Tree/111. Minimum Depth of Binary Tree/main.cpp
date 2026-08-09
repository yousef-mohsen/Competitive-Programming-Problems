//
//  main.cpp
//  111. Minimum Depth of Binary Tree
//
//  Created by Yousef on 09.06.26.
//

#include <iostream>
#include <climits>

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
    int ans = INT_MAX;
    int minDepth(TreeNode* root) {
        
        if(root)
        {
            dfs(root, 1);
            return ans;
        }
        else return 0;
        
        
    }
    void dfs(TreeNode * n, int depth)
    {
        if(!n->left && !n->right)
        {
            ans = min(ans, depth);
            return;
        }
        
        if(n->left)
            dfs(n->left, depth + 1);
        
        if(n->right)
            dfs(n->right, depth + 1);
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
