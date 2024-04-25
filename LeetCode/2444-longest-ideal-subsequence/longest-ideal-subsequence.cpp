class Solution {
private:
    int solve(int ind, char prev, string &s, int &k, int &n, vector<vector<int>> &dp){
        if(ind == n)
            return 0;

        if(dp[ind][prev-'a'] != -1)
            return dp[ind][prev-'a'];

        int take = 0, notTake = 0;
        notTake = solve(ind + 1, prev, s, k, n, dp);
        if(prev == '{' || abs(s[ind] - prev) <= k){
            take = 1 + solve(ind + 1, s[ind], s, k, n, dp);
        }
        
        return dp[ind][prev-'a'] = max(take, notTake);
    }

public:
    int longestIdealString(string s, int k) {
        int ind = 0;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(27, -1));
        return solve(ind, '{', s, k, n, dp);
    }
};