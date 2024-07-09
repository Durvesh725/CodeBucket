class Solution {
public:
    long long getDescentPeriods(vector<int>& prices){
        int n = prices.size();
        int left = 0;
        int right = 1;
        long count = 1;

        while(right < n){
            if(prices[right-1] - prices[right] != 1){
                left = right;
            }
            count += (right - left + 1);
            right++;
        }

        return count;
    }
};