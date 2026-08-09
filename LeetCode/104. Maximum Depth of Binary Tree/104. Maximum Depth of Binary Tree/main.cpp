//
//  main.cpp
//  104. Maximum Depth of Binary Tree
//
//  Created by Yousef on 20.05.26.
//

#include <iostream>
#include <vector>
#include <map>

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
    
    
    int dfs (TreeNode* node){
        
        int maximum = 1;
        if (node->left != nullptr)
        {
            
            maximum = 1 + dfs(node->left);
        }
        
        if (node->right != nullptr)
        {
            
            maximum = max(maximum, 1 + dfs(node->right));
        }
        
        return maximum;
    }
    
    int maxDepth(TreeNode* root) {
        if(root)
        {
            return dfs(root);
            
        }
        return 0;
        
    }
    
};

int main(int argc, const char * argv[]) {
    
    
    return EXIT_SUCCESS;
}
