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

   void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){      
        if(col==n) ans.push_back(board);
        for(int row=0;row<n;row++){
            if(issafe(row,col,n,board)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        solve(0,board,ans,n);
        return ans;
    }
};