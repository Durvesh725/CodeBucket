class Solution {
public:
    int sum=0;
    int solve(int i,int t, vector<int> &nums, vector<vector<int>>& dp){
        if(i<0){
            return t==0;
        }
        // if(dp[i][t+sum]!=-1)    return dp[i][t+sum];
        int np=0,p=0;
        // if(t-nums[i]>=0 && t- nums[i]<=tar){
            np=solve(i-1,nums[i]-t,nums,dp);
        // }
        // if(nums[i]+t>=0 && t+nums[i]<=tar)
            p=solve(i-1,nums[i]+t,nums,dp); 

        return p+np;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        // int sum=0;
        for(int i:nums)
            sum+=i;
        
        vector<vector<int>> dp(n,vector<int>(sum*2+2,-1));
        return solve(n-1,target,nums,dp);
    }
};