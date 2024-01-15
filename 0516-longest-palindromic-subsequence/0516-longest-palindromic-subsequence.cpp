class Solution {
private:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        //Tabulation----
        //n+1, m+1 because we are storing BC itself
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        //BC
        //Shifting of indexes concept, consider 0 and -1 and return 0, therefore
        for(int j = 0; j <= m; j++){
            dp[0][j] = 0;
        }
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }
        
        //i <= n because we have shifted one index right
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
        
            }
        }
        return dp[n][m];
    }
    
public:
    int longestPalindromeSubseq(string s) {
        string srev = s;
        reverse(srev.begin(), srev.end());
        return longestCommonSubsequence(s, srev);
    }
};