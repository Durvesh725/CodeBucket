class Solution {
private:
    int solve(int ind, vector<int> &dp){
        if(ind <= 1)
            return 1;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int ways = solve(ind-1, dp) + solve(ind-2, dp);
        return dp[ind] = ways;
    }
    
public:
    int climbStairs(int n) {
    vector<int> dp(n+1, -1);
    return solve(n, dp);
    }
};