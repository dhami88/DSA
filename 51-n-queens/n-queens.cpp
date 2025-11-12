class Solution {
    bool issafe(int row,int col,vector<string>&board,int n){
        int duprow=row;
        int dupcol=col;
       while(row>=0&&col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
       }
       row=duprow;
       col=dupcol;
       while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
       }
      row=duprow;
       col=dupcol;
       while(row<n&&col>=0){
        if(board[row][col]=='Q') return false;
        row++;
        col--;
       }
       return true;
    }


    vector<vector<string>>solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
        if(col==n) ans.push_back(board);
        for(int row=0;row<n;row++){
            if(issafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        
        }
        return ans;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        return solve(0,board,ans,n);
    }
};