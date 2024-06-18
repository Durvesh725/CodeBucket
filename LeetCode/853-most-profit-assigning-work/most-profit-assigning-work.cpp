class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(), worker.end());
        vector<pair<int, int>> dp;
        
        int n = difficulty.size();
        for(int i = 0; i < n; i++)
            dp.push_back({difficulty[i], profit[i]});

        sort(dp.begin(), dp.end());

        n = worker.size();
        int j = 0;
        int tempMax = 0;
        int maxProfit = 0;
        for(int i = 0; i < n; i++){
            while(j < n && dp[j].first <= worker[i]){
                tempMax = max(tempMax, dp[j].second);
                j++;
            }
            maxProfit += tempMax;
            j = 0;
            tempMax = 0;
        }

        return maxProfit;
    }
};