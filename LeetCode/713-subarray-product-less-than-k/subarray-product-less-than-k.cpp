class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        long long prod = 1;
        int subarrays = 0;
        while(right < n){
            prod *= nums[right];

            while(prod >= k && left <= right){
                prod /= nums[left];
                left++;
            }

            subarrays += (right - left + 1);
            right++;
        }

        return subarrays;
    }
};