class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int Sn = (n*(n+1))/2;
        int S = 0;
        for(int i=0; i<n; i++){
            S+=nums[i];
        }
        return Sn - S;
    }
};