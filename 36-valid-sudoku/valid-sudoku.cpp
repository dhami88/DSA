class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //rows
       for(int i=0;i<9;i++){
        unordered_set<char>st;
        for(int j=0;j<9;j++){
            if(board[i][j]=='.') continue;
            if(st.count(board[i][j])) return false;
            st.insert(board[i][j]);
        }
       }
       //columns
       for(int j=0;j<9;j++){
         unordered_set<char>s;
        for(int i=0;i<9;i++){
            if(board[i][j]=='.') continue;
            if(s.count(board[i][j])) return false;
            s.insert(board[i][j]);
        }
       }
       //squares
        for (int square = 0; square < 9; square++) {
            unordered_set<char> seen;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (board[row][col] == '.') continue;
                    if (seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }
       return true;
    }
};