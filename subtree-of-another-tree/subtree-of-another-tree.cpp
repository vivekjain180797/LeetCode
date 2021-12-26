/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
private :
    bool isSametree(TreeNode *root1, TreeNode *root2){
      if(!root1 || !root2) return (root1==root2);
      return root1->val == root2->val && isSametree(root1->left,root2->left) && isSametree(root1->right,root2->right);
    }
    
public:
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(!root) return false;
        return isSametree(root,subroot) || isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
    }
};