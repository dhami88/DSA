class Solution {
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,long long &size){
        vis[node]=1;
        size++;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,size);
            }
        }

    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        long long rem=n;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                long long size=0;
                dfs(i,vis,adj,size);
                rem-=size;
                ans+=size*rem;
            }
        }
        return ans;
    }
};