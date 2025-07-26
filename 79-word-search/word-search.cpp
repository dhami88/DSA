class Solution {
    bool f(vector<vector<char>>& board,string &word,int ind,int i,int j,vector<vector<int>>&vis){
        vis[i][j]=1;
         int n=board.size();
        int m=board[0].size();
        if(ind==word.size()) return true;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,1,-1};
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&
            vis[nr][nc]==0&&board[nr][nc]==word[ind]){
               if(f(board,word,ind+1,nr,nc,vis)) return true;
            }
        }
        vis[i][j]=0;
      return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(board[i][j]==word[0]){
             if(f(board,word,1,i,j,vis)) return true;
               } 
            }
        }
        return false;
    }
};