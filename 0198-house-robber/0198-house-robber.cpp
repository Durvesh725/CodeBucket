//similar question like max sum of non adjacent ele DP

class Solution {
private:
    int solve(int ind, vector<int> &nums, vector<int> &dp){
        if(ind == 0)
            return nums[ind];
        
        if(ind < 0)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        //pick
        int pick = nums[ind] + solve(ind-2, nums, dp);
        
        //not pick
        int notpick = 0 + solve(ind-1, nums, dp);
        
        return dp[ind] = max(pick, notpick);
    }
    
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, -1);
        return solve(size-1, nums, dp);        
    }   
};