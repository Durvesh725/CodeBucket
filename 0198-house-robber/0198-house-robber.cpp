class Solution {
public:
    int helper(vector<int>& nums, int idx, int n, vector<int>&dp){
        if(idx >= n)
            return 0;
        
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        //pick or not pick
        return dp[idx] = max((helper(nums, idx+2, n,dp)+nums[idx]), helper(nums, idx+1, n,dp));
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return helper(nums, 0, n, dp);   
    }
};