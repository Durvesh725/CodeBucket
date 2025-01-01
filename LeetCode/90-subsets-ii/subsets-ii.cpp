class Solution {
private:
    void solve(vector<int>& nums,  set<vector<int>> &ans, vector<int> output, int index){
        if(index >= nums.size()){
            //special case if elements inside vector are same but order is changed
            // sort(output.begin(), output.end());
            ans.insert(output);
            return;
        }

        //exclude
        solve(nums, ans, output, index+1);

        //include
        output.push_back(nums[index]);
        solve(nums, ans, output, index+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int> output;
        vector<vector<int>> finall;
        int index = 0;
        solve(nums, ans, output, index);   

        for(auto i: ans){
            finall.push_back(i);
        }
        return finall;
    }
};