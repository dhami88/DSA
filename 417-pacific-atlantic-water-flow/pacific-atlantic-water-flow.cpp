class Solution {
    void dfs(int i,int j,vector<vector<int>>&heights,vector<vector<int>>&vis){
        int n=heights.size();
        int m=heights[0].size();
        vis[i][j]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && heights[nr][nc]>=heights[i][j]){
                dfs(nr,nc,heights,vis);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>pac(n,vector<int>(m,0));
        vector<vector<int>>atl(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dfs(0,i,heights,pac);
        }
        for(int i=0;i<m;i++){
            dfs(n-1,i,heights,atl);
        }
        for(int j=0;j<n;j++){
            dfs(j,0,heights,pac);
        }
        for(int j=0;j<n;j++){
            dfs(j,m-1,heights,atl);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j]==1&&atl[i][j]==1) ans.push_back({i,j});
            }
        }
        return ans;
    }
};