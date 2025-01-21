class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int m = grid[0].size();
        long long secondMin = LLONG_MAX;
        long long usum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long lsum = 0;

        for(int i = 0; i < m; i++){
            usum -= grid[0][i];
            secondMin = min(secondMin, max(usum, lsum));
            lsum += grid[1][i];
        }

        return secondMin;
    }
};