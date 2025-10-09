class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int m=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,m});
                adj[j].push_back({i,m});
            }
        }
        //now finding the mst
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(n,0);
        pq.push({0,0});
        int ans=0;
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(vis[node]==1) continue;
            vis[node]=1;
            ans+=wt;
            for(auto it:adj[node]){
                int no=it.first;
                int ww=it.second;
                if(!vis[no]){
                    pq.push({ww,no});
                }
            }
        }
        return ans;
    }
};