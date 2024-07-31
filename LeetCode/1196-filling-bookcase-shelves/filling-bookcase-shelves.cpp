class Solution {
public:
    int n;
    int org_width;

    int solve(int ind, vector<vector<int>>& books, int r_width, int max_h, vector<vector<int>> &dp){
        if(ind >= n)
            return max_h;

        if(dp[ind][r_width] != -1)
            return dp[ind][r_width];

        int w = books[ind][0];
        int h = books[ind][1];

        int take = INT_MAX, not_take = INT_MAX;
        if(w <= r_width){
            take = solve(ind + 1, books, r_width - w, max(max_h, h), dp);
        }
  
        not_take = max_h + solve(ind + 1, books, org_width - w, h, dp);

        return dp[ind][r_width] = min(take, not_take);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {\
        n = books.size();
        org_width = shelfWidth;
        vector<vector<int>> dp(n, vector<int>(shelfWidth + 1, -1));

        return solve(0, books, shelfWidth, 0, dp);
    }
};