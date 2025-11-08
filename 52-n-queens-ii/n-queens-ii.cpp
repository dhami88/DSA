class Solution {
    bool issafe(int row,int col,int n,vector<string>&board){
        //upper diag
        int duprow=row;
        int dupcol=col;
        while(row>=0&&col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        //left
        row=duprow;
        col=dupcol;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        //lower diag
        row=duprow;
        col=dupcol;
        while(row<n&&col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
     }

   void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n,int &cnt){      
        if(col==n){
            ans.push_back(board);
            cnt++;
        } 
        for(int row=0;row<n;row++){
            if(issafe(row,col,n,board)){
                board[row][col]='Q';
                solve(col+1,board,ans,n,cnt);
                board[row][col]='.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        int cnt=0;
        solve(0,board,ans,n,cnt);
        return cnt;
    }
};