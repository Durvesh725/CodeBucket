class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n-1;
        vector<int> res(2, 0);

        while(i < j){
            if(nums[i] + nums[j] == target){
                res[0] = i + 1;
                res[1] = j + 1;
                return res;
            }
            else if(nums[i] + nums[j] < target){
                i++;
            }
            else{
                j--;
            }
        }

        return {-1, -1};
    }
};