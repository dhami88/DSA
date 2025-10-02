class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        int MOD=(int)1e9+7;
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        vector<long long>dist(n,1e18);
        dist[0]=0;
        vector<long long>ways(n,0);
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            long long dis=it.first;
            int node=it.second;
            pq.pop();
            for(auto it:adj[node]){
                int n=it.first;
                long long d=it.second;
                if(dis+d<dist[n]){
                    dist[n]=dis+d;
                    pq.push({dist[n],n});
                    ways[n]=ways[node];
                }
                else if(dis+d==dist[n]){
                    ways[n]=(ways[n]+ways[node])%MOD;
                }
            }
        }
    return ways[n-1];

    }
};