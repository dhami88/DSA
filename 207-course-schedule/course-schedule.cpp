class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
       vector<vector<int>>adj(n);
       for(auto it:prerequisites){
        int u=it[0];
        int v=it[1];
        adj[v].push_back(u);
       }
       //topo sort using kahns algo 
       queue<int>q;
       vector<int>inorder(n,0);
       for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            inorder[it]++;
        }
       }
       for(int i=0;i<n;i++){
        if(inorder[i]==0) q.push(i);
       }
       vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                inorder[it]--;
                if(inorder[it]==0) q.push(it);
            }
        }
   if(topo.size()==n) return true;
   return false;


    }
};