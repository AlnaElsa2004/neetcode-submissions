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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result="";
        if(!root){
           return "null,";
            
        }
        result+=to_string(root->val)+",";
        result+=serialize(root->left);
        result+=serialize(root->right);
        return result;

    }
     int pos=0;
  TreeNode* deserialize(string data) {
         
        string token = "";

        while (pos < data.size() && data[pos] != ',') {
            token += data[pos];
            pos++;
        }

        pos++; // skip comma

        if (token == "null")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(token));

        root->left = deserialize(data);
        root->right = deserialize(data);

        return root;
    }

};
