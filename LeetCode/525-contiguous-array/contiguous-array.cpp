class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //store first occ of each unique prefix sum in a map
        //prefixSum here is to neutralize
        unordered_map<int, int> um{{0, -1}};
        int ans = 0;
        int ps = 0;
        for(int i = 0; i < nums.size(); i++){
            ps += nums[i] == 1 ? 1 : -1;
            if(um.count(ps))
                ans = max(ans, i - um[ps]);
            else
                um[ps] = i;
        }
        return ans;
    }
};