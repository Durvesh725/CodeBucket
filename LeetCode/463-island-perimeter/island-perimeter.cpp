class Solution {
private:
    int calculate(int i, int j, vector<vector<int>>& grid, int &m, int &n){
        int t = 0;
        if(i == 0 || grid[i-1][j] == 0)
            t++;
        if(i == n-1 || grid[i+1][j] == 0)
            t++;
        if(j == 0 || grid[i][j-1] == 0)
            t++;
        if(j == m-1 || grid[i][j+1] == 0)
            t++;

        return t;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    res += calculate(i, j, grid, m, n);
                }
            }
        }
        return res;
    }
};