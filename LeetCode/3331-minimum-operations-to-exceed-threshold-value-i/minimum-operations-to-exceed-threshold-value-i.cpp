class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(auto &it : nums){
            if(it < k){
                ans++;
            }
        }
        return ans;
    }
};

// 1 2 3 10 11