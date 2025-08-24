class Solution {
    int dfs(int headID,vector<vector<int>>&adj,vector<int>& informTime,int curtime){
        int maxtime=curtime;
    //     if (adj[headID].empty())
    // return curtime;
        for(auto it:adj[headID]){
           maxtime=max(maxtime, dfs(it,adj,informTime,curtime+informTime[headID]));
        }
        return maxtime;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
           if(manager[i]!=-1) adj[manager[i]].push_back(i);
        }
        return dfs(headID,adj,informTime,0);

    }
};