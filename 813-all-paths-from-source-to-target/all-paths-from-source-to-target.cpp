class Solution {
    void dfs(int node,vector<int>&path,vector<vector<int>>& graph, vector<vector<int>>&ans){
        int n=graph.size();
      //  vis[node]=1;
        path.push_back(node);
        if(node==n-1){
          ans.push_back(path);
        }
        for(auto it:graph[node]){
                dfs(it,path,graph,ans);
        }
       // vis[node]=0;
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int n=graph.size();
        vector<int>path;
        vector<int>vis(n,0);
        dfs(0,path,graph,ans);
        return ans;

    }
};