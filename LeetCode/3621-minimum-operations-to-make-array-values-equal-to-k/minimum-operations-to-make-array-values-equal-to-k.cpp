class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        if((st.size() == 1) && (nums[0] == k)){
            return 0;
        }

        int op = 0;
        for(auto it: st){
            if(it > k){
                op++;
            }
        }

        sort(nums.begin(), nums.end());
        if(op > 0 && k <= nums[0]){
            return op;
        }
        return -1;
    }
};