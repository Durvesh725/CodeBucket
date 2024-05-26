class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int solve(int n, int absent, int c_late){
        //why this condition before? because if AA, then we have to return 0 and not 1
        if(absent >= 2 || c_late >= 3)
            return 0;

        if(n == 0)
            return 1;

        if(dp[n][absent][c_late] != -1)
            return dp[n][absent][c_late];

        int a = solve(n-1, absent + 1, 0) % M;
        int l = solve(n-1, absent, c_late + 1) % M;
        int p = solve(n-1, absent, 0) % M;

        return dp[n][absent][c_late] = ((a + l) % M + p) % M;
    }

    int checkRecord(int n) {
        dp = vector<vector<vector<int>>>(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(n, 0, 0); 
    }
};