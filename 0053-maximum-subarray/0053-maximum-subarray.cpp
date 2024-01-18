class Solution {
public:
    int maxSubArray(vector<int>& nums) {    
        // int n = nums.size();
        // int maxi = INT_MIN;
        // for(int i = 0; i < n; i++){
        //     int sum = 0;
        //     for(int j = i; j < n; j++){
        //         sum += nums[j];
        //         maxi = max(maxi, sum);
        //         cout << maxi;
        //     }
        // }
        // return maxi;
        
        int maxi = INT_MIN;
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            
            //keep track of maximum sun;
            if(sum > maxi)
                maxi = sum;
            
            if(sum < 0)
                sum = 0;
        }
        return maxi;
    }
};