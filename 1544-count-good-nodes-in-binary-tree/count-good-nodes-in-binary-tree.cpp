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
int preorder(TreeNode* root,int maxi){
    if (root==NULL) return 0;
    int cnt=0;
    if(root->val>=maxi) cnt=1; 
     maxi=max(maxi,root->val);
    if(root->left)  cnt+=preorder(root->left,maxi);
    if(root->right) cnt+=preorder(root->right,maxi);
    return cnt;
 }

class Solution {
public:
    int goodNodes(TreeNode* root) {
       if(root==NULL) return 0;
      return preorder(root,root->val);     
    }
};