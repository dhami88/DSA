class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        // Build an adjacency list to represent the tree.
        // This makes it easy to find neighbors for any node.
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Initialize the answer vector.
        vector<int> ans(n, 0);
        
        // Start the DFS traversal from the root (node 0).
        // -1 indicates that the root has no parent.
        DFS(0, -1, adj, labels, ans);
        return ans;
    }
    
private:
    // This DFS function returns a frequency map (vector of 26 ints)
    // of all characters in the subtree of the current `node`.
    vector<int> DFS(int node, int parent, vector<vector<int>>& adj, string& labels, vector<int>& ans) {
        // Create a frequency map for the subtree rooted at the current `node`.
        vector<int> count(26, 0);
        
        // Count the current node's label first.
        count[labels[node] - 'a'] = 1;
        
        // Recursively visit all children of the current node.
        for (int child : adj[node]) {
            // This check prevents us from going back up the tree to the parent.
            if (child == parent) continue;
            
            // Get the frequency map from the child's subtree.
            vector<int> childCount = DFS(child, node, adj, labels, ans);
            
            // Merge the child's frequency map into the current node's map.
            for (int i = 0; i < 26; i++) {
                count[i] += childCount[i];
            }
        }
        
        // After processing all children, `count` now holds the total frequencies
        // for the entire subtree of the current `node`.
        // We can now find the answer for this node.
        ans[node] = count[labels[node] - 'a'];
        
        // Return the complete frequency map to the parent node.
        return count;
    }
};