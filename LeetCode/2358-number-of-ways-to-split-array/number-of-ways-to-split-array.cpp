class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int rs = accumulate(nums.begin(), nums.end(), 0LL);
        // int ls = nums[0];
        long long int ls = 0;
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            ls += nums[i];
            rs -= nums[i];
            if(ls >= rs)
                ans++;
        }
        return ans;
    }
};