class Solution {
public:
    bool isPossible(vector<vector<char>>& grid, int i, int j){
        int W = 0, B = 0;
        for(int x = i; x < i + 2; x++){
            for(int y = j; y < j + 2; y++){
                if(grid[x][y] == 'W') W++;
                else B++;
            }
        }
        if(W > 2 || B > 2) return 1;
        return 0;
    }
    bool canMakeSquare(vector<vector<char>>& grid){
        int n = grid.size();
        for(int i = 0; i <= n - 2; i++){ 
            for(int j = 0; j <= n - 2; j++){
                if(isPossible(grid, i, j)) return 1;
            }
        }
        return 0;
    }
};