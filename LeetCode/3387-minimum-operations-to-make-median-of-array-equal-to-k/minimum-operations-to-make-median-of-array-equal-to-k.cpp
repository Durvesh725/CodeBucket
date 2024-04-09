class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = n/2;
        if(nums[m] == k)
            return 0;

        long long op = 0;
        if(k <= nums[m]){
            for(int i = 0; i <= m ; i++){
                if(nums[i] > k) op += nums[i] - k;
            }
        }
        else{
            for(int i = m; i < n ; i++){
                if(nums[i] <= k) op += k - nums[i];
            }
        }
        return op;
    }
};

// 1000000000