class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>mat(m,vector<int>(n,0));
       for(auto it:guards){
        mat[it[0]][it[1]]=1;
       }
       for(auto it:walls){
        mat[it[0]][it[1]]=2;
       }
       int dr[]={-1,0,1,0};
       int dc[]={0,1,0,-1};
           
           for(auto it:guards){
            int i=it[0];
            int j=it[1];
            for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
               while(nr>=0&&nr<m&&nc>=0&&nc<n){
                  if(mat[nr][nc]==1||mat[nr][nc]==2) break;
                  if(mat[nr][nc]==0) {
                    mat[nr][nc]=3;
                  }
                    nr=nr+dr[k];
                    nc=nc+dc[k];
                  
                }
            }
           }
       int count=0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0) count++;
        }
       }
       return count;
    }
};