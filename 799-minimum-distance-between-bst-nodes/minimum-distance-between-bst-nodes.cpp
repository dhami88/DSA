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
    vector<int>inorder(TreeNode* root,vector<int>&ghewar){
       if(root->left) inorder(root->left,ghewar);
        ghewar.push_back(root->val);
      if(root->right)  inorder(root->right,ghewar);
        return ghewar;
    }
public:
    int minDiffInBST(TreeNode* root) {
       //inorder traversal of bst gives nodes in sorted order
       if(root==NULL) return 0;
       vector<int>ghewar;
       inorder(root,ghewar); 
       int ans=INT_MAX;
       for(int i=0;i<ghewar.size()-1;i++){
        ans=min(ans,abs(ghewar[i]-ghewar[i+1]));
        cout<<ghewar[i];
       }
       return ans;
    }
};