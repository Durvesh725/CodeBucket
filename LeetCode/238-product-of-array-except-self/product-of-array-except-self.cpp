class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        int lp = 1;
        for (int i = 0; i < n; i++) {
            ans[i] *= lp;
            lp *= nums[i];
        }

        int rp = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= rp;
            rp *= nums[i];
        }

        return ans;
    }
};

// 