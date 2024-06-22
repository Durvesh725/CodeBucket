class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int rs = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int ls = 0;
        for(int i = 0; i < n; i++){
            rs -= nums[i];
            if(ls == rs)
                return i;
            ls += nums[i];
        }
        return -1;
    }
};