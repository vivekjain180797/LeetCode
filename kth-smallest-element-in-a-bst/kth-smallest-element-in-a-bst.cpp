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
public:
   void inorder(TreeNode* node, int& fid, int& k) {
    if (!node) return;
    inorder(node->left, fid, k);
    if (!k) return;
    fid = node->val;
    inorder(node->right, fid, --k);
}

int kthSmallest(TreeNode* root, int k) {
    int fid;
    inorder(root, fid, k);
    return fid;
}
};