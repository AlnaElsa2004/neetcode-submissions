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
int maxi;
int maxp(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int lefp=max(0,maxp(root->left));
    int righp=max(0,maxp(root->right));
    maxi=max(maxi,(root->val+lefp+righp));
    return root->val+max(lefp,righp);

}
    int maxPathSum(TreeNode* root) {
       maxi=INT_MIN;
       maxp(root);
       return maxi;
    }
};
