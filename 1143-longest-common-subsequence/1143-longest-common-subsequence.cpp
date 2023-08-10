class Solution {
    //using top-down DP approch
    private:
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>>& dp){
        //base case
        if(i == s1.length())
            return 0;
        if(j == s2.length())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        if(s1[i] == s2[j]){
            ans = 1 + solve(s1, s2, i+1, j+1, dp);
        }
        else{
            ans = max(solve(s1, s2, i+1, j, dp), solve(s1, s2, i, j+1, dp));
        }
        return dp[i][j] = ans;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        //create 2d DP
        vector<vector<int> > dp(text1.length(), vector<int>(text2.length(), -1));
        return solve(text1, text2, 0, 0, dp);   
    }
};