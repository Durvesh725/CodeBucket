class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int op = 0;
        int i = 0;
        while(i < nums.size() && nums[i] < k){
            nums.erase(nums.begin());
            op++;
        }
        return op;
    }
};

// 1 2 3 10 11