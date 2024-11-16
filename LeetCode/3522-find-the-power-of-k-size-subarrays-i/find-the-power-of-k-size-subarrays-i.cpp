class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        int maxi = INT_MIN;

        for(int i = 0; i <= n-k; i++){
            bool flag = true;
            maxi = nums[i];
            for(int j = i + 1; j < i + k; j++){
                if(nums[j] != nums[j-1] + 1){
                    flag = false;
                }
                else{
                    maxi = max(maxi, nums[j]);
                }
            }

            if(flag)
                res.push_back(maxi);
            else   
                res.push_back(-1);
        }

        return res;
    }
};