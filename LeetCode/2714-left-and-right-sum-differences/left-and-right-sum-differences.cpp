class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> arrLeft(n);
        vector<int> arrRight(n);
        vector<int> ans(n);

        arrLeft[0] = 0;
        for(int i = 1; i < n; i++){
            arrLeft[i] = arrLeft[i-1] + nums[i-1];
        }
        
        arrRight[0] = 0;
        for(int i = n-2; i >= 0; i--){
            arrRight[i] = arrRight[i+1] + nums[i+1];
        }

        for(int i = 0; i < n; i++){
            ans[i] = abs(arrLeft[i] - arrRight[i]);
        }

        return ans;
    }
};