class Solution {
private:
    void solve(vector<int>& nums, set<vector<int>>& ans, int index){
        if(index >= nums.size()){
            ans.insert(nums);
            return;
        }

        for(int j = index; j<nums.size(); j++){
            swap(nums[index], nums[j]);
            solve(nums, ans, index+1);
            //helps to not alter the next result while backtracking
            swap(nums[index], nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //set to avoid duplicate elements
        set<vector<int>> ans;
        vector<vector<int>> finall;
        int index = 0;
        solve(nums, ans, index);

        for(auto i: ans){
            finall.push_back(i);
        }
        return finall;
    }
};