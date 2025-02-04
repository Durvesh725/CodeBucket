class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = 0;
        int i = 1;
        int n = nums.size();
        int maxi = INT_MIN;
        bool f = true;

        while(i < n){
            if(nums[i-1] < nums[i]){
                sum += nums[i-1];
                f = true;
            }
            else{
                f = false;
                sum += nums[i-1];
                maxi = max(maxi, sum);
                sum = 0;
            }
            i++;
        }

        if(f){
            sum += nums[n-1];
            maxi = max(sum, maxi);
        }

        return maxi;
    }
};