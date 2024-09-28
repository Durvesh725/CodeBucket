class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        vector<int> ans;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i]&1){
                odd.push_back(nums[i]);
            }
            else{
                even.push_back(nums[i]);
            }
        }

        int ind1 = 0, ind2 = 0;
        for(int i = 0; i < n; i++){
            if(i&1){
                ans.push_back(odd[ind1++]);
            }
            else{
                ans.push_back(even[ind2++]);
            }
        } 

        return ans;  
    }
};