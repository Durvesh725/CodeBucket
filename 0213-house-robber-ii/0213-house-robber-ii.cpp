class Solution {
private:
    int solve(vector<int> &arr){
    //SO
    int prev = arr[0];
    int prev2 = 0;
    for(int i = 1; i < arr.size(); i++){
        int pick = arr[i];
        if(i > 1)
            pick += prev2;
        int notpick = 0 + prev;
        
        int curri = max(pick, notpick);

        prev2 = prev;
        prev = curri;
    }
    return prev;
}
    
public:
    int rob(vector<int>& nums) {
        vector<int> t1, t2;
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        for(int i = 0; i < n; i++){
            if(i != 0)
                t1.push_back(nums[i]);
            if(i != n-1)
                t2.push_back(nums[i]);
        }
        
        int ans1 = solve(t1);
        int ans2 = solve(t2);
        
        return max(ans1, ans2);
    }
};