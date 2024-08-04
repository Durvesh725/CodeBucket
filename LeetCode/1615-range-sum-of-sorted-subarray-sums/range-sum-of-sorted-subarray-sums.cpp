class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        vector<int> sums;
        for(int i = 0; i < n; i++){
            long long int s = 0;
            for(int j = i; j < n; j++){
                s += nums[j];
                sums.push_back(s);
            }
        }

        sort(sums.begin(), sums.end());
    
        long long int final_sum = 0;
        for(int i = left - 1; i <= right-1; i++){
            final_sum += sums[i];
        }

        return final_sum % MOD;
    }
};