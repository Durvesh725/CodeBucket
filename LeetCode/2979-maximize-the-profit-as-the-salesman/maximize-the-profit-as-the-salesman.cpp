class Solution {
public:
    static bool cmp(vector<int> &a, vector<int>&b){
        return a[0] < b[0];
    }

    int solve(int ind, vector<vector<int>>& offers, vector<int> &dp){
        if(ind == offers.size())
            return 0;

        if(dp[ind] != -1)
            return dp[ind];

        int np = solve(ind + 1, offers, dp);

        int p = offers[ind][2];
        //search on remaining space
        int low = ind + 1;
        int high = offers.size()-1;
        int nextPossibleInd = offers.size();
        while(low <= high){
            int mid = (low+high)/2;
            if(offers[mid][0] > offers[ind][1]){
                nextPossibleInd = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        p += solve(nextPossibleInd, offers, dp);

        return dp[ind] = max(np, p);
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int n1 = offers.size();
        vector<int> dp(n1+1, -1);

        //1. we sort the results based on start time to deal with overlapping intervals
        sort(offers.begin(), offers.end(), cmp);
        return solve(0, offers, dp);
    }
};