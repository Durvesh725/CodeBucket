class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long sum = 0;
        long maxFreq = 0;
        long l = 0, r = 0;

        for(r = 0; r < n; r++){
            sum += nums[r];

            if(l < r && (nums[r] * (r-l+1)) > sum + k){
                sum -= nums[l];
                l++;
            }

            maxFreq = max(maxFreq, r - l + 1);
        }

        return maxFreq;
    }
};