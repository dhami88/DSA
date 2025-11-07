class Solution {
    bool issafe(int row,int col,vector<string>&board,int n){
        for(int r=row-1,c=col-1;r>=0&&c>=0;r--,c--){
            if(board[r][c]=='Q') return false;

        }
        for(int c=col-1;c>=0;c--){
            if(board[row][c]=='Q') return false;
        }
        for(int r=row+1,c=col-1;r<n&&c>=0;r++,c--){
            if(board[r][c]=='Q') return false;
        }
        return true;
    }
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++){
            if(issafe(row,col,board,n)){
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