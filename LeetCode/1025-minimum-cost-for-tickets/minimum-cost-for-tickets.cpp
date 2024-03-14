class Solution {
private:
    int solve(int ind, vector<int>& days, vector<int>& costs, vector<int> &dp){
        if(ind >= days.size())
            return 0; //0 cost
        
        if(dp[ind] != -1)
            return dp[ind];

        int day1 = costs[0] + solve(ind+1, days, costs, dp);
        
        int i;

        for(i = ind; i < days.size() && days[i] < days[ind] + 7; i++);
        int day7 = costs[1] + solve(i, days, costs, dp);

        for(i = ind; i < days.size() && days[i] < days[ind] + 30; i++);
        int day30 = costs[2] + solve(i, days, costs, dp);

        return dp[ind] = min(day1, min(day7, day30));
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1, -1);
        return solve(0, days, costs, dp);
    }
};