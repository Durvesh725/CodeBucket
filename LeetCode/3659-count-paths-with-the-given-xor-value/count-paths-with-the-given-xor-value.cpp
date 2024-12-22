class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int i, int j, int curr, int n, int m, vector<vector<int>>& grid, int &k, vector<vector<vector<int>>>& dp){
        if(i >= m || j >= n)
            return 0;

        curr ^= grid[i][j];

        if(i == m-1 && j == n-1){
            return curr == k;
        }

        if(dp[i][j][curr] != -1)
            return dp[i][j][curr];

        int down = solve(i+1, j, curr, n, m, grid, k, dp) % mod;
        int right = solve(i, j+1, curr, n, m, grid, k, dp) % mod;

        return dp[i][j][curr] = (down + right) % mod;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(16, -1)));
        return solve(0, 0, 0, n, m, grid, k, dp);
    }
};