class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>vis(n,vector<int>(n,0));
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        while(!pq.empty()){
            int cost=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            int delr[]={-1,0,1,0};
            int delc[]={0,-1,0,1};
            if(r==n-1&&c==n-1) return cost;
            for(int k=0;k<4;k++){
                int nr= r+delr[k];
                int nc=c+delc[k];
                if(nr>=0&&nr<n&&nc>=0&&nc<n&&vis[nr][nc]==0){
                   int e =max(cost,grid[nr][nc]);
                   pq.push({e,{nr,nc}});
                   vis[nr][nc]=1;
                }
            }
        }
        return -1;
    }
};