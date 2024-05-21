class Solution {
private:
    void solve(int ind, vector<int> &nums, vector<vector<int>> &res, vector<int> &temp){
        if(ind >= nums.size()){
            res.push_back(temp);
            return;
        }

        //exclude
        solve(ind+1, nums, res, temp);

        //include
        temp.push_back(nums[ind]);
        solve(ind+1, nums, res, temp);

        temp.pop_back();
    }


public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(0, nums, res, temp);
        return res;
    }
};