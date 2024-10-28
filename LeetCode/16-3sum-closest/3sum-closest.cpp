class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int minDiff = INT_MAX;
        int ans = 0;

        for(int i = 0; i <= n - 3; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    int sum = nums[i] + nums[j] + nums[k];
                    int diff = abs(target - sum);
                    if(diff < minDiff){
                        minDiff = diff;
                        ans = sum;
                    }
                }
            }
        }

        return ans;
    }
};