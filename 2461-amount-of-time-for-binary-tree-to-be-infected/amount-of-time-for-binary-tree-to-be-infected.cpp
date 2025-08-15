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
 TreeNode*parentpointer(TreeNode*root,int start, unordered_map<TreeNode*,TreeNode*>&m){
    queue<TreeNode*>q;
    q.push(root);
    TreeNode*res;
    while(!q.empty()){
        TreeNode*node=q.front();
        if(node->val==start) res=node;
        q.pop();
        if(node->left){
            m[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            m[node->right]=node;
            q.push(node->right);
        }
        
    }
     return res;
 }
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>m;
        TreeNode*ini=parentpointer(root,start,m);
        unordered_map<TreeNode*,int>vis;
        queue<TreeNode*>q;
        q.push(ini);
        vis[ini]=1;
        int t=0;
        while(!q.empty()){
            int size=q.size();
         for(int i=0;i<size;i++){
             TreeNode*node=q.front();
             q.pop();
            if(node->left&&vis[node->left]==0){
                vis[node->left]=1;
                q.push(node->left);
            }
            if(node->right&&vis[node->right]==0){
                vis[node->right]=1;
                q.push(node->right);
            }
            if(m[node]&&vis[m[node]]==0){
                vis[m[node]]=1;
                q.push(m[node]);
            }
         }
            t++;
        }
        return t-1;
    }
};