class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //bitwise and of two unequal nos is always less than the maximum of two numbers

        int maxi = *max_element(nums.begin(), nums.end());
        int max_len = 0, len = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == maxi){
                max_len = max(max_len, ++len);
            }
            else
                len = 0;
        }

        return max_len;
    }
};