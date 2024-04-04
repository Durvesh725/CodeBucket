class Solution {
public:
    vector<vector<int>> dp;
    vector<int> nums;

    int solve(int l, int r, int t){
        if(l >= r)  return 0;

        if(dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;
        if(nums[l] + nums[l+1] == t)
            ans = max(ans, 1 + solve(l+2, r, t));
        if(nums[r] + nums[r-1] == t)
            ans = max(ans, 1 + solve(l, r-2, t));
        if(nums[l] + nums[r] == t)
            ans = max(ans, 1 + solve(l+1, r-1, t));

        return dp[l][r] = ans;
    }


    int maxOperations(vector<int>& arr) {
        nums = arr;
        int n = nums.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        int op1 = solve(0, n-1, nums[0]+nums[1]);

        dp = vector<vector<int>>(n, vector<int>(n, -1));
        int op2 = solve(0, n-1, nums[0]+nums[n-1]);

        dp = vector<vector<int>>(n, vector<int>(n, -1));
        int op3 = solve(0, n-1, nums[n-2]+nums[n-1]);

        return max({op1, op2, op3});
    }
};