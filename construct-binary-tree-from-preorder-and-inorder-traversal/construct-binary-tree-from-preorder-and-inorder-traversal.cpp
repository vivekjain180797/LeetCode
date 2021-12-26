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
    int rootIndex;
    TreeNode* builder(vector<int>& preorder, vector<int>& inorder, int left, int right){
        if(left > right) return nullptr;
        int pivot = left;
        while(inorder[pivot]!=preorder[rootIndex]) pivot++;
        rootIndex++;
        TreeNode* root = new TreeNode(inorder[pivot]);
        root->left =  builder(preorder,inorder,left, pivot-1);
        root->right = builder(preorder,inorder,pivot+1,right);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        rootIndex = 0;
        return builder(preorder,inorder,0,inorder.size()-1);
    }
};