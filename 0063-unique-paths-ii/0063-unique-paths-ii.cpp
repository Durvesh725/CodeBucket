class Solution {
private:
    int solve(int m, int n, vector<vector<int>> &og, int srcx, int srcy, vector<vector<int>> &dp){
        //BC
        if(srcx == m-1 && srcy == n-1){
            return 1;
        }
        
        if(srcx >= m || srcy >= n){
            return 0;
        }
        
        if(dp[srcx][srcy] != -1)    return dp[srcx][srcy];
        
        //right
        int right = 0;
        if(srcy+1 < n && og[srcx][srcy+1] != 1)
            right = solve(m, n, og, srcx, srcy+1, dp);
        
        //down
        int down = 0;
        if(srcx+1 < m && og[srcx+1][srcy] != 1)
            down = solve(m, n, og, srcx+1, srcy, dp);
        
        int count = right + down;
        
        return dp[srcx][srcy] = count;
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>&og) {
        //obstacle at beg only: edge case
        if(og[0][0]==1)
            return 0;
        
        int m = og.size();
        int n = og[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m, n, og, 0, 0, dp);
    }
};