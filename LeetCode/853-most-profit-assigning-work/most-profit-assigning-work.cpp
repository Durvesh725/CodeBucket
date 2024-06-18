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
        int lastDiff = 0;
        for(int i = 0; i < n; i++){
            // if(worker[i] > lastDiff){
            //     j = 0;
            //     tempMax = 0;
            // }

            cout << "j: " << j << endl;
            while(j < n && dp[j].first <= worker[i]){
                tempMax = max(tempMax, dp[j].second);
                lastDiff = dp[j].first;
                j++;
            }
            cout << lastDiff << endl;
            maxProfit += tempMax;
        }

        return maxProfit;
    }
};