class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                um[nums[i][j]]++;
            }
        }

        vector<int> ans;
        int n = nums.size();
        for(auto it: um){
            if(it.second == n)
                ans.push_back(it.first);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};