class Solution {
public:
    int solve(vector<int>& rewardValues, int ind, int x, vector<vector<int>> &dp){
        if(ind >= rewardValues.size())
            return 0;

        if(dp[ind][x] != -1)
            return dp[ind][x];

        int take = 0;
        if(x < rewardValues[ind]){
            take = rewardValues[ind] + solve(rewardValues, ind + 1, x + rewardValues[ind], dp);
        }

        int nottake = solve(rewardValues, ind + 1, x, dp);

        return dp[ind][x] = max(take, nottake);
        
    }


    int maxTotalReward(vector<int>& rewardValues) {
        vector<vector<int>> dp(2001, vector<int>(4000, -1));
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        return solve(rewardValues, 0, 0, dp);
    }
};