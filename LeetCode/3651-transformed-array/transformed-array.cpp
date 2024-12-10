class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                res[i] = nums[(i + nums[i]) % n];
            }
            else if(nums[i] < 0){
                int shift = (-nums[i]) % n;
                int newIndex = (i - shift + n) % n; 
                res[i] = nums[newIndex];
            }
            else{
                res[i] = nums[i];
            }
        } 

        return res;  
    }
};