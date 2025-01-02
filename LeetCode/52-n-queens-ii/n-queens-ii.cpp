class Solution {
public:
    bool isSafe(vector<string> board, int row, int col, int n){
        int nrow = row;
        int ncol = col;

        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q')  return false;
            row--;
            col--;
        }

        row = nrow;
        col = ncol;
        while(col >= 0){
            if(board[row][col] == 'Q')  return false;
            col--;
        }

        row = nrow;
        col = ncol;
        while(row < n && col >= 0){
            if(board[row][col] == 'Q')  return false;
            row++;
            col--;
        }

        return true;
    }

    void solve(int col, int n, vector<string> &board, int &cnt){
        if(col == n){
            cnt++;
            return;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(board, row, col, n)){
                board[row][col] = 'Q';
                solve(col+1, n, board, cnt);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int cnt = 0;

        solve(0, n, board, cnt);
        return cnt;
    }
};