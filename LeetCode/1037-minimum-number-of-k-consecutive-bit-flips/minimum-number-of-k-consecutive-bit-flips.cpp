class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<int> isFlipped(n, 0);
        int flipCount = 0;
        
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                flipCount ^= isFlipped[i - k];
            }
            if (nums[i] == flipCount) {
                if (i + k > n) {
                    return -1;
                }
                ans++;
                flipCount ^= 1;
                isFlipped[i] = 1;
            }
        }
        return ans;
    }
};
