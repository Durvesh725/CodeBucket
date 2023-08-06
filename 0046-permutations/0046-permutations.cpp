class Solution {
    //we are making change in original array
private:
    void solve(vector<int>& nums, vector<vector<int>> &ans, int index){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }

        //increments ith index at topmost
        //place each letter on ith index to make combination
        for(int j = index; j<nums.size(); j++){
            swap(nums[index], nums[j]);
            solve(nums, ans, index+1);
            swap(nums[index], nums[j]); //backtracking
            //as we are changing original array, we need to nutralise the changes made during recursive call
            //so that when the base case reaches, the original array remains as it is for next iteration
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        return ans;
    }
};