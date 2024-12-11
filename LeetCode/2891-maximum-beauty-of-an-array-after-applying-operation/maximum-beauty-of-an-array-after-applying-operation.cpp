class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(2 * (1e5 + 1), 0);

        for(int i = 0; i < n; i++){
            int startidx = nums[i] - k;
            int endidx = nums[i] + k;

            if(startidx <= 0)
                pre[0] += 1;
            else
                pre[startidx] += 1;

            pre[endidx + 1] -= 1;
        }

        int res = 0;
        int n2 = pre.size();
        for(int i = 1; i < n2; i++){
            pre[i] += pre[i-1];
            res = max(res, pre[i]);
        }

        return res;
    }
};