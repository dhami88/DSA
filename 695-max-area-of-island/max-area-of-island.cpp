class Solution {
    int dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>& grid){
         int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        int cnt=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]==0&&grid[nr][nc]==1){
               cnt+=dfs(nr,nc,vis,grid);
                
            }
        }
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0&&grid[i][j]==1){
                   int res=dfs(i,j,vis,grid);
                   ans=max(ans,res);
                }
            }
        }
        return ans;
    }
};