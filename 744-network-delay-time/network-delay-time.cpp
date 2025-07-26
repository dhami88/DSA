class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n,1e9);
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:times){
            int u=it[0]-1;
            int v=it[1]-1;
            int t=it[2];
            adj[u].push_back({v,t});
        }
        pq.push({0,k-1});
        dist[k-1]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int next=it.first;
                int d=it.second;
                if(dist[next]>dis+d){
                    dist[next]=dis+d;
                    pq.push({dist[next],next});
                }
            }
       
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dist[i]==1e9) return -1;
            else {
                ans=max(ans,dist[i]);
            }
        }
        return ans;
    }
};