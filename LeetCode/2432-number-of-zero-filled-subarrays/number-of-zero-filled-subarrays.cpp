class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int sub = 1;
        long long total_sub = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                total_sub += sub;
                sub++;
            }
            else{
                sub = 1;
            }
        }
        return total_sub;
    }
};