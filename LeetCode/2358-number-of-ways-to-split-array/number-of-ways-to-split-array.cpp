class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        long long int rs = 0;
        long long int ls = 0;
        for (int i = 0; i < n; i++) {
            rs += nums[i];
        }
        // int ls = nums[0];
        for(int i = 0; i < n-1; i++){
            ls += nums[i];
            rs -= nums[i];
            if(ls >= rs)
                ans++;
        }
        return ans;
    }
};