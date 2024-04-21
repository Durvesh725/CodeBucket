class Solution {
public:
    vector<vector<int>> dp;

    int solve(int c, int keep, vector<vector<int>>& grid, int &m, int &n){
        if(c >= m)
            return 0;

        if(dp[c][keep] != -1)
            return dp[c][keep];

        int cost = 0, minAns = INT_MAX;
        for(int i = 0; i < n; i++){
            cost += (grid[i][c] != keep);
        }

        for(int option = 0; option <= 9; option++){
            if(option == keep)  continue;
            minAns = min(minAns, cost + solve(c + 1, option, grid, m, n));
        }

        return dp[c][keep] = minAns;
    }

    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int minAns = INT_MAX;
        dp = vector<vector<int>> (m, vector<int>(10, -1));
        for(int keep = 0; keep <= 9; keep++){
            minAns = min(minAns, solve(0, keep, grid, m, n));
        }

        return minAns;
    }
};