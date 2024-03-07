class Solution {
private:
    int solve(vector<vector<int>>& grid, int for_y, int for_other){
        int n = grid.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //check t-l-c, t-r-c, c-b
                if((i <= n/2 && (i == j || i+j == n-1)) || (i > n/2 && j == n/2)){
                    if(grid[i][j] != for_y)  ans++;
                }
                else{
                    if(grid[i][j] != for_other) ans++;
                }
            }
        }
        return ans;
    }

public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        return min({solve(grid, 0, 1), solve(grid, 0, 2),
                    solve(grid, 1, 0), solve(grid, 1, 2),
                    solve(grid, 2, 0), solve(grid, 2, 1)});
    }
};

//three cases for checking Y
//top left to center: i <= n/2 && i == j
//top right to center: i+j == n-1
//center to bottom: i >= n/2