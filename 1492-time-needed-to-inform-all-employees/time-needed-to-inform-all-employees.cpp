class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
           if(manager[i]!=-1) adj[manager[i]].push_back(i); 
        }
        q.push({headID,0});
        int maxi=0;
        while(!q.empty()){
            int node=q.front().first;
            int time=q.front().second;
            maxi=max(maxi,time);
            q.pop();
            for(auto it:adj[node]){
                q.push({it,time+informTime[node]});
            }
        }
        return maxi;
    }
};