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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode* ,int>>q;
        q.push({root,0});
       long long  int ans=0;
        while(!q.empty()){
           // TreeNode*node=q.front().first;
           long long  int first,last;//har ek level pr ek first index or ek last index hoga        
           long long int size=q.size();
           long long int mini=q.front().second;
            for(int i=0;i<size;i++){
                TreeNode*node=q.front().first;
               long long int cur_ind= q.front().second-mini;
                q.pop();
                if(node->left) q.push({node->left,(cur_ind*2)+1});
                if(node->right) q.push({node->right,(cur_ind*2)+2});
                if(i==0) first=cur_ind;
                if(i==size-1) last=cur_ind;
            }
                ans=max(ans,last-first+1);
            
        }
        return ans;
    }
};