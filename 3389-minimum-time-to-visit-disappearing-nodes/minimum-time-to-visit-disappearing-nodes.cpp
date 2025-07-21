class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int>dist(n,1e9);
        dist[0]=0;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int t=it[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(time>=disappear[node]) continue;
            if(time>dist[node]) continue;

            for(auto it:adj[node]){
                int next=it.first;
                int dis=it.second;
                if(time+dis<dist[next]&& time+dis<disappear[next]){
                    dist[next]=time+dis;
                    pq.push({dist[next],next});
                }

            }

        }
        for(int i=0;i<n;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        return dist;
    }
};