class Solution {
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,int destination){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,destination);
            }
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        
            if(!vis[source]){
                dfs(source,vis,adj,destination);
            }
       if(vis[destination]==0) return false;
       return true;
    }
};