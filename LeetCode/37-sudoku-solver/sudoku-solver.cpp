class Solution {
public:
    bool solve(vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == '.'){
                   
                   for(char c = '1'; c <= '9'; c++){
                        if(isValid(i, j, board, c)){
                            board[i][j] = c;

                        if(solve(board) == true)
                            return true;
                        else
                            //resets the value in selected cell from previous state to empty cell
                            board[i][j] = '.';
                    }
                   }
                   //if cant be placed in row and col as well, return false to the solve fun
                   return false;
                }
            }
        }
        return true; //if the entire board is filled
    }

    bool isValid(int &row, int &col, vector<vector<char>> &board, int c){
        int n = board.size();
        for(int i = 0; i < n; i++){
            if(board[i][col] == c)
                return false;
            if(board[row][i] == c)
                return false;

            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c)
                return false;
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};