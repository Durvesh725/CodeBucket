class Solution {
public:
    int solve(int ind, vector<int> &nums, int n, vector<int> &dp){
        if(ind >= n){
            return 0;
        }

        if(dp[ind] != -1)
            return dp[ind];

        int pick = nums[ind] + solve(ind + 2, nums, n, dp);
        int not_pick = solve(ind+1, nums, n, dp);

        return dp[ind] = max(pick, not_pick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];

        vector<int> dp(n, -1);
        vector<int> dp2(n, -1);

        return max(solve(1, nums, n, dp), solve(0, nums, n-1, dp2));
    }
};