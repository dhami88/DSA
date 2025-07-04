class Solution {
    void dfs(int i,int j, vector<vector<int>>&vis,vector<vector<char>>& grid){
         int n=grid.size();
       int m=grid[0].size();
        vis[i][j]=1;
        int delr[]={-1,0,1,0};
        int delc[]={0,-1,0,1};
        for(int k=0;k<4;k++){
            int nr=delr[k]+i;
            int nc=delc[k]+j;
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]==0&&grid[nr][nc]=='1'){
                dfs(nr,nc,vis,grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0)); 
       int cnt=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0&&grid[i][j]=='1'){
                dfs(i,j,vis,grid);
                cnt++;
            }
        }
       }
       return cnt;
    }
};