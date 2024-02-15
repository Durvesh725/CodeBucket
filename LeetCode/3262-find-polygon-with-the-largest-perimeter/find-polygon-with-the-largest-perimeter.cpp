class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }

        for(int i = nums.size()-1; i >= 0; i--){
            sum -= nums[i];
            if(sum > nums[i])
                return sum + nums[i];
        }
        return -1;
    }
    // 1 1 2 3 5 12 50
};