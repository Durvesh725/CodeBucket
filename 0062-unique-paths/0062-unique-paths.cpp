class Solution {
private:
    int solve(int m, int n, int srcx, int srcy, vector<vector<int>> &dp){
        //BC
        if(srcx == m-1 && srcy == n-1){
            return 1;
        }
        
        if(srcx >= m || srcy >= n){
            return 0;
        }
        
        if(dp[srcx][srcy] != -1)    return dp[srcx][srcy];
        
        int right = solve(m, n, srcx, srcy+1, dp);
        int down = solve(m, n, srcx+1, srcy, dp);
        
        int count = right + down;
        
        return dp[srcx][srcy] = count;
    }
    
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m, n, 0, 0, dp);
    }
};