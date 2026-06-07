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
     TreeNode* build(string& data, int& pos) {

        string token = "";

        while (pos < data.size() && data[pos] != ',') {
            token += data[pos];
            pos++;
        }

        pos++; // skip comma

        if (token == "null")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(token));

        root->left = build(data, pos);
        root->right = build(data, pos);

        return root;
    }

    TreeNode* deserialize(string data) {
        int pos = 0;
        return build(data, pos);
    }
};
 