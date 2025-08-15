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
bool isSame(TreeNode* s, TreeNode* t) {
    if (!s && !t) return true;  // both NULL
    if (!s || !t) return false; // one NULL, one not
    return (s->val == t->val) && 
           isSame(s->left, t->left) && 
           isSame(s->right, t->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return false; // reached end
    if (isSame(root, subRoot)) return true; // match found here
    // Otherwise, check left and right
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
};