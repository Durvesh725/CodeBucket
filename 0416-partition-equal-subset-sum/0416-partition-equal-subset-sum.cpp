class Solution {
private:
    bool solve(int ind, int target, vector<int>& nums, vector<vector<int>> &dp){
        if(target == 0)
            return true;
        
        if(ind == 0)
            return (nums[0] == target);
        
        if(dp[ind][target] != -1)
            return dp[ind][target];
            
        bool not_take = solve(ind-1, target, nums, dp);
        bool take = false;
        if(target >= nums[ind]){
            take = solve(ind-1, target - nums[ind], nums, dp);
        }
            
        return dp[ind][target] = take | not_take;
    }
    
public:
    bool canPartition(vector<int>& nums) {    
        int totalSum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            totalSum += nums[i];
        }
        
        //odd number % 2 always gives 1
        if(totalSum % 2)
            return false;
        
        int target = totalSum/2;
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        return solve(n-1, target, nums, dp);
    }
};