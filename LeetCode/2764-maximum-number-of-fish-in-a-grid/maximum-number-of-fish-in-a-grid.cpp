class Solution {
public:
    int bfs(int i, int j, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        int row_arr[4] = {-1, 0, +1, 0};
        int col_arr[4] = {0, +1, 0, -1};

        queue<pair<int, int>> q;
        q.push({i, j});

        int tempFish = 0;
        while(!q.empty()){
            int curr_row = q.front().first;
            int curr_col = q.front().second;
            q.pop();
            tempFish += grid[curr_row][curr_col];
            grid[curr_row][curr_col] = 0;

            for(int i = 0; i < 4; i++){
                int nrow = curr_row + row_arr[i];
                int ncol = curr_col + col_arr[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] != 0){
                    tempFish += grid[nrow][ncol];
                    grid[nrow][ncol] = 0;
                    q.push({nrow, ncol});
                }
            }
        }
        return tempFish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxFish = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] > 0){
                    maxFish = max(maxFish, bfs(i, j, grid));
                }
            }
        }

        return maxFish;
    }
};