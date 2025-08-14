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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return {};
        map<int,map<int,multiset<int>>>m;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            TreeNode*node=it.first;
            int vertical=it.second.first;
            int level=it.second.second;
            m[vertical][level].insert(it.first->val);
            q.pop();
            if(node->left) q.push({node->left,{vertical-1,level+1}});
            if(node->right) q.push({node->right,{vertical+1,level+1}});
        }
        for(auto it:m){
            vector<int>aisehi;
            for(auto x:it.second){
                for(auto y:x.second){
                    aisehi.push_back(y);
                }
            }
            ans.push_back(aisehi);
        }
        return ans;
    }
};