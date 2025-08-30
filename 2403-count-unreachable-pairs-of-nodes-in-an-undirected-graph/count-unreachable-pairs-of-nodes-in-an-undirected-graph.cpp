class Solution {
    void bfs(int node,vector<vector<int>>&adj,vector<int>&vis,long long &size){
        int n=adj.size();
        vis[node]=1;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int no=q.front();
            size++;
            q.pop();
            for(auto it:adj[no]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
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
        for (int i=0;i<n;i++){
            if(!vis[i]){
                long long size=0;
                bfs(i,adj,vis,size);
                rem-=size;
                ans+=size*rem;
            }
        }
        return ans;
    }
};