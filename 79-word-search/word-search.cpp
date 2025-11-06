class Solution {
    bool dfs(int i,int j,vector<vector<char>>& board,string word,int index,vector<vector<int>>&vis){
        vis[i][j]=1;
         int n=board.size();
        int m=board[0].size();
        if(index==word.size()) return true;
        int delr[]={-1,0,1,0};
        int delc[]={0,-1,0,1};
        for(int k=0;k<4;k++){
            int nr=i+delr[k];
            int nc=j+delc[k];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]==0){
                if(board[nr][nc]==word[index]){
                    if(dfs(nr,nc,board,word,index+1,vis)) return true;
                }
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
                    if(dfs(i,j,board,word,1,vis)) return true;
                }
            }
        }
        return false;
    }
};