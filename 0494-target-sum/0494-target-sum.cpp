class Solution {
public:
    int solve(int i,int t, vector<int> &nums){
        if(i<0){
            return t==0;
        }
        
        int np=solve(i-1,nums[i]-t,nums);
        int p=solve(i-1,nums[i]+t,nums);
        
        return p+np;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(n-1,target,nums);
    }
};