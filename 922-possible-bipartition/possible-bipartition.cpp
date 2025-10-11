class Solution {
    bool dfs(int node,int colour,vector<int>&color,vector<vector<int>>&adj){
        color[node]=colour;
        for(auto it:adj[node]){
            if(color[it]==-1){
               if(dfs(it,!colour,color,adj)==false) return false;
            }
            else if(color[it]==colour) return false;
        }
        return true;

    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto it:dislikes){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
// now check for bipartite graph
       vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
               if(dfs(i,0,color,adj)==false) return false;;
            }
        }
        return true;
    }
};