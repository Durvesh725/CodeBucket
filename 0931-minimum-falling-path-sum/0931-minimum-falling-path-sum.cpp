class Solution {
private:
//     int solve(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp){
//         //diagonally overflow
//         if(j < 0 || j >= n)
//             return 1e8;    //because we need max path sum
        
//         if(i == 0)
//             return matrix[0][j];    //because we have variable starting too
        
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//         int up = matrix[i][j] + solve(i-1, j, n, matrix, dp);
//         int ld = matrix[i][j] + solve(i-1, j-1, n, matrix, dp);
//         int rd = matrix[i][j] + solve(i-1, j+1, n, matrix, dp);
        
//         return dp[i][j] = min(up, min(ld, rd));
//     }
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
//         int mini = 1e8;
//         for(int j = 0; j < n; j++){
//             mini = min(mini, solve(n-1, j, n, matrix, dp));
//         }
//         return mini;
        
        //TABULATION
        //BC
        for(int j = 0; j < n; j++){
            dp[0][j] = matrix[0][j];
        }
        
        //States
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                int up = matrix[i][j] + dp[i-1][j];
                
                int ld = matrix[i][j];
                if(j-1 >= 0)
                    ld += dp[i-1][j-1];
                else
                    ld += 1e8;
                
                int rd = matrix[i][j];   
                if(j+1 < n)
                    rd += dp[i-1][j+1];
                else
                    rd += 1e8;
                
                dp[i][j] = min(up, min(ld, rd));
            }
        }
        
        int mini = dp[n-1][0];
        for(int j = 1; j < n; j++){
            mini = min(mini, dp[n-1][j]);
        }
        
        return mini;
    }
};