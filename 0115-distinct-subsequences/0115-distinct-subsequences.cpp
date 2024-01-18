class Solution {
private:
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        //if string t completely matches
        if(j < 0)
            return 1;
        
        //if s has exhausted we still have some character in t to be matched
        if(i < 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        //if character matches
        //second solve function: check for other possiblities of the j in i, because we need to match j in i
        if(s[i] == t[j])
            return dp[i][j] = solve(i-1, j-1, s, t, dp) + solve(i-1, j, s, t, dp);
        
        return dp[i][j] = solve(i-1, j, s, t, dp);
    }
    
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, s, t, dp);
    }
};