class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        if(n==1&&grid[0][0]==1) return -1;
        if(grid[0][0]==1||grid[n-1][n-1]==1) return -1;
        q.push({1,{0,0}});
        dist[0][0]=1;
        while(!q.empty()){
            int dis=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr=r+i;
                    int nc=c+j;
                    if(nr>=0&&nr<n&&nc>=0&&nc<n&&grid[nr][nc]==0){
                        if(dis+1<dist[nr][nc]){
                        q.push({dis+1,{nr,nc}});
                        dist[nr][nc]=1+dis;
                        }
                        if(nr==n-1&&nc==n-1) return dist[nr][nc];
                    }
                }
            }
        }

      return -1;
    }
};