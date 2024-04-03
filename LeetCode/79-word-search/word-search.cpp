class Solution {
private:
    //DFS
    bool search(int ind, int i, int j, string &word, vector<vector<char>>& board){
        if(ind == word.size())
            return true;

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;

        bool ans = false;
        if(word[ind] == board[i][j]){
            board[i][j] = '*';

            ans = search(ind+1, i-1, j, word, board) || 
                  search(ind+1, i, j+1, word, board) ||
                  search(ind+1, i+1, j, word, board) ||
                  search(ind+1, i, j-1, word, board);
            
            //backtrack
            board[i][j] = word[ind];
        }
        return ans;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        //find starting point
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(word[0] == board[i][j]){
                    if(search(0, i, j, word, board))
                        return true;
                }
            }
        }
        return false;
    }
};