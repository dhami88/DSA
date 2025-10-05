class Solution {
    void dfs(int i,int j,vector<vector<int>>& heights,
    vector<vector<int>>&vis){
         int n=heights.size();
        int m=heights[0].size();
        vis[i][j]=1;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int dr=i+dx[k];
            int dc=j+dy[k];
            if(dr>=0&&dr<n&&dc>=0&&dc<m&&vis[dr][dc]==0&&heights[dr][dc]>=heights[i][j]){
                dfs(dr,dc,heights,vis);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>pac(n,vector<int>(m,0));
        vector<vector<int>>atl(n,vector<int>(m,0));
        //pacific ocean se cell mai pani tab jayega jab next wala cell usse bada hoga
            for(int i=0;i<n;i++){
                dfs(i,0,heights,pac);
            }
            for(int j=0;j<m;j++){
                dfs(0,j,heights,pac);
            }
            for(int k=0;k<m;k++){
                dfs(n-1,k,heights,atl);
            }
            for(int l=0;l<n;l++){
                dfs(l,m-1,heights,atl);
            }
            vector<vector<int>>ans;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(pac[i][j]&&atl[i][j]){
                        ans.push_back({i,j});
                    }
                }
            }
            return ans;
    }
};