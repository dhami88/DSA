class Solution {
    bool dfs(int i,int c,vector<int>&color,vector<vector<int>>& graph){
        color[i]=c;
        for (auto it:graph[i]){
            if(color[it]==-1){
               if(dfs(it,!c,color,graph)==false) return false;
            }
            else {
                if(color[it]==c) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
               if(dfs(i,0,color,graph)==false) return false;
            }
        }
        return true;
    }
};