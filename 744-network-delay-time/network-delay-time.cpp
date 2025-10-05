class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for (auto it:times){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int dis=it.second;
                int no=it.first;
                if(dis+wt<dist[no]){
                    dist[no]=dis+wt;
                    pq.push({dist[no],no});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
          
            if(dist[i]==1e9) return -1;
             else ans=max(ans,dist[i]);
            
        }
        return ans;
    }
};