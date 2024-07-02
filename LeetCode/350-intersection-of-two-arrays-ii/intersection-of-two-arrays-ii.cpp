class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        vector<int> ans;
        int n = nums2.size();

        for(auto it: nums1){
            um[it]++;
        }

        for(int i = 0; i < n; i++){
            if(um[nums2[i]] > 0){
                ans.push_back(nums2[i]);
                um[nums2[i]]--;
            }
        }

        return ans;
    }
};