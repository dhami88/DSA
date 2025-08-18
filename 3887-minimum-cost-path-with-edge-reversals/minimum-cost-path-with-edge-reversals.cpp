class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        

        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        int ans=-1;
        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto &[v,w]:adj[u]){
               if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                } 
            }

        }
        return (dist[n-1]==INT_MAX)?-1:dist[n-1];
    }
};