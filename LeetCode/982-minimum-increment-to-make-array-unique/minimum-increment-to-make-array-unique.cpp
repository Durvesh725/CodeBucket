class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int moves = 0;
        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i+1] = nums[i+1] + 1;
                moves++;
            }

            if(nums[i+1] < nums[i]){
                moves += (nums[i] - nums[i+1] + 1);
                nums[i+1] = nums[i+1] + ((nums[i] - nums[i+1]) + 1);
            }
        }

        return moves;
    }
};