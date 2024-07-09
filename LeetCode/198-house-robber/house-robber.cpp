class Solution {
private:
    int solve(int ind, vector<int> &nums, vector<int> &dp){
        if(ind >= nums.size())
            return 0;
        
        if(ind == nums.size()-1)
            return nums[ind];

        if(dp[ind] != -1)
            return dp[ind];

        int pick = nums[ind] + solve(ind+2, nums, dp);
        int not_pick = solve(ind+1, nums, dp);

        return dp[ind] = max(pick, not_pick);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp); // Start from index 0
    }
};
