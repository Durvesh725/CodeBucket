class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        um[0] = 1;
        int ps = 0, cnt = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            ps += nums[i];
            int remove = ps - k;
            cnt += um[remove];
            um[ps]++;
        }
        return cnt;
    }
};