class Solution {
private:
    void bfs(vector<vector<char>>& grid, vector<vector<int>> &vis, int row, int col, int &m, int &n){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int row_arr[4] = {-1, 0, 1, 0};
            int col_arr[4] = {0, 1, 0, -1};
            for(int k = 0; k < 4; k++){
                int nrow = row + row_arr[k];
                int ncol = col + col_arr[k];

                if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m 
                && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int island = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    island++;
                    bfs(grid, vis, i, j, m, n);
                }
            }
        }
        return island;
    }
};