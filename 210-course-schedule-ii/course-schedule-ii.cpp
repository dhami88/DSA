class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
       vector<vector<int>>adj(n);
       for(auto it:prerequisites){
        int u=it[0];
        int v=it[1];
        adj[v].push_back(u);
       } 
       vector<int>inorder(n,0);
       for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            inorder[it]++;
        }
       }
       vector<int>topo;
       queue<int>q;
       for(int i=0;i<n;i++){
        if(inorder[i]==0) q.push(i);
       }
       while(!q.empty()){
        int node=q.front();
        topo.push_back(node);
        q.pop();
        for (auto it:adj[node]){
            inorder[it]--;
            if(inorder[it]==0) q.push(it);
        }
       }
       if(topo.size()==n) return topo;
       else return {} ;
    }
};