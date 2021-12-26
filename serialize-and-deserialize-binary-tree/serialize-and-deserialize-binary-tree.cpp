/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



/* A good problem to learn stringstream --> clear(), str() , input to output << , output read >> (ostringstream , istringstream), part of <sstream> */

class Codec {
    
private :
    
    void seralizeUsingOstringStream(TreeNode* root, ostringstream &out){
        if(root){
            out << root->val << " ";
            seralizeUsingOstringStream(root->left,out);
            seralizeUsingOstringStream(root->right,out);
        } else {
            out << "# ";
        }
    }
    
    TreeNode* deseralizeUsingIstringStream(istringstream &in){
        string val;
        in >> val;
        if(val=="#") 
            return nullptr;
        TreeNode *temp = new TreeNode(stoi(val));
        temp->left = deseralizeUsingIstringStream(in);
        temp->right = deseralizeUsingIstringStream(in);
        return temp;
    }
    
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        seralizeUsingOstringStream(root,out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deseralizeUsingIstringStream(in);
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));