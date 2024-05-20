class Solution {
private:
    int solve(vector<int>& nums, int cxor, int ind){
        if(ind == nums.size()) return cxor;

        int include = solve(nums, cxor^nums[ind], ind + 1);
        int exclude = solve(nums, cxor, ind + 1);

        return include + exclude;
    }

public:
    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};