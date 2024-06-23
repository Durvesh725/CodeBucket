class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = n/2, cnt = 0;
        double mini = 51.0;
        int left = 0, right = n-1;
        while(cnt <= count){
            double avg = (nums[left++]+nums[right--])/2.0;
            mini = min(mini, avg);
            cnt++;
        }
        return mini;
    }
};