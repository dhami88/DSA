class Solution {
    void dfs(int i,vector<vector<int>>& connections,vector<int>&vis,     vector<vector<int>>&adj){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it,connections,vis,adj);
            }
        }

    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
     int m=connections.size();
     if(m<n-1) return -1;
     vector<vector<int>>adj(n);
     for(auto it:connections){
        int u=it[0];
        int v=it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
     vector<int>vis(n,0);
     int cnt=0;
     for(int i=0;i<n;i++){
    if(!vis[i]) {dfs(i,connections,vis,adj);
     cnt++;
    }
     }
    return cnt-1;
    }
};