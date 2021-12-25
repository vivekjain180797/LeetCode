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
private:
    int maxPathSumHelper(TreeNode* root, int &max_val) {
        if(!root) return 0;
        int l = max(maxPathSumHelper(root->left,max_val),0);
        int r = max(maxPathSumHelper(root->right,max_val),0);
        int new_val = root->val + l + r;
        max_val = max(max_val,new_val);
        return root->val + max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
      int max_val = INT_MIN;
      maxPathSumHelper(root, max_val);
      return max_val;
    }
};