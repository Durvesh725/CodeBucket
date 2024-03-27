class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0;
        int cnt = 0;
        while(i < nums.size()){
            int p = 1;
            int j = i;
            while(j < nums.size() && p < k){
                p *= nums[j];
                if(p < k){
                    j++;
                    cnt++;
                }
            }
            i++;
        }
        return cnt;
    }
};