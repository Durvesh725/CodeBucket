class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buy = prices[0];
        int tempProfit = 0;
        int n = prices.size();

        for(int i = 0; i < n; i++){
            buy = min(buy, prices[i]);
            tempProfit = prices[i] - buy;
            maxProfit = max(maxProfit, tempProfit);
        }

        return maxProfit;
    }
};