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
    int dfs(TreeNode* root,int maxv){
       if(root==NULL){
        return 0;
       }
       int count=0;
       if(root->val>=maxv){
        count=1;
       }
       maxv=max(maxv,root->val);
       count+=dfs(root->left,maxv);
       count+=dfs(root->right,maxv);
       return count;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};
