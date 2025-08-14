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
 vector<int>preorder(TreeNode* root,int level,vector<int>&ans){
        if(ans.size()==level) ans.push_back(root->val);
        if(root->right) preorder(root->right,level+1,ans);
        if(root->left) preorder(root->left,level+1,ans);
        return ans;
 }
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        //reverse preorder traversal
        //root right left
        if(root==NULL) return {};
        vector<int>ans;
        return preorder(root,0,ans);
    }
};