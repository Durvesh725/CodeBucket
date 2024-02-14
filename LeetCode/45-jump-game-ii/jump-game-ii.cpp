class Solution {
public:
    int jump(vector<int>& nums) {
        //1. at each index, maintain the maximum jump
        for(int i = 1; i < nums.size(); i++){
            nums[i] = max(i+nums[i], nums[i-1]);
        }
        int i = 0;
        int jumps = 0;
        while(i < nums.size()-1){
            jumps++;
            i=nums[i];
        }
        return jumps;
    }
};