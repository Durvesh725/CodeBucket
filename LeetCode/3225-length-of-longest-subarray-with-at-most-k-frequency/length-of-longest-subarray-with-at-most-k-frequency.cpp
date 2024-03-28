class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int i = 0;
        int j = 0;
        int ml = 0;
        while(j < nums.size()){
            um[nums[j]]++;
            while(um[nums[j]] > k){
                um[nums[i]]--;
                i++;
            }
            ml = max(ml, j - i + 1);
            j++;
        }
        return ml;
    }
};
