class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == target)
                return i;
        }

        for(int i = 0; i < n; i++){
            if(target < nums[i]){
                return i;
            }
            else if(i == n-1 && target > nums[i]){
                return i + 1;
            }
        }

        return -1;
    }
};