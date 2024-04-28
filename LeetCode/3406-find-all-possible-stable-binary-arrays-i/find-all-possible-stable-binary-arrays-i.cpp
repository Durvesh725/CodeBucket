class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(int one, int zero, bool prev, int limit, vector<vector<vector<int>>> &dp){
        if(one == 0 && zero == 0)   return 1;

        int ans = 0;
        if(dp[one][zero][prev] != -1)
            return dp[one][zero][prev];

        if(prev == true){
            for(int i = 1; i <= min(one, limit); i++){
                ans = (ans + solve(one-i, zero, false, limit, dp))%MOD;
            }
        }
        else if(prev == false){
            for(int i = 1; i <= min(zero, limit); i++){
                ans = (ans + solve(one, zero-i, true, limit, dp))%MOD;
            }
        }

        return dp[one][zero][prev] = ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(one+1, vector<vector<int>>(zero+1, vector<int>(2, -1)));
        //prev = true - next is 1
        //prev = false - next is 0
        int zerofirst = solve(one, zero, true, limit, dp);
        int onefirst = solve(one, zero, false, limit, dp);
        return (zerofirst + onefirst)%MOD;
    }
};