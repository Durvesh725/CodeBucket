class Solution {
public:
    int n;
    int solve(int person, int i, int M, vector<int> &piles, vector<vector<vector<int>>> &dp){
        if(i >= n)
            return 0;
        
        if(dp[person][i][M] != -1)
            return dp[person][i][M];

        int stones = 0;
        int res = (person == 1) ? -1 : INT_MAX;
        for(int x = 1; x <= min(2*M, n-i); x++){
            stones += piles[i+x-1];
            //alice
            if(person == 1){
                res = max(res, stones + solve(0, i+x, max(M, x), piles, dp));
            }
            else{
                res = min(res, solve(1, i+x, max(M, x), piles, dp));
            }
        }

        return dp[person][i][M] = res;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(101, vector<int>(101, -1)));
        //          person, index, M
        return solve(1, 0, 1, piles, dp);
    }
};