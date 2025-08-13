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
 int height(TreeNode* root,int &maxi){
    if(root==NULL) return 0;
    int lh=height(root->left,maxi);
    int rh=height(root->right,maxi);
    maxi=max(maxi,lh+rh);
    return 1+max(lh,rh);
 }
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        //diameter mtlv longest distance between any 2 nodes
        int maxi=0; 
        height(root,maxi);
        return maxi;
;    }
};