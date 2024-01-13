class Solution {
private:
    int solve(int ind, int target, vector<int> &coins, vector<vector<int>> &dp){
        //design base case considering there is only one element left in an array
        if(ind < 0){
            return (target == 0);
        }
        
        if(dp[ind][target] != -1)
            return dp[ind][target];
        
        int not_take = solve(ind-1, target, coins, dp);
        int take = 0;
        if(coins[ind] <= target){
            take = solve(ind, target - coins[ind], coins, dp);
        }
        
        return dp[ind][target] = take + not_take;
    }
    
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(n-1, amount, coins, dp);
    }
};