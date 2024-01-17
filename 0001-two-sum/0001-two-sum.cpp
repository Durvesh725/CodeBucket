class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> ans;
        // int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     for(int j = i + 1; j < n; j++){
        //         if(nums[i] + nums[j] == target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }
        // return ans;
        
        
        vector<int> ans;
        unordered_map<int, int> um;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(um.find(target-nums[i]) != um.end()){
                ans.push_back(um[target-nums[i]]);
                ans.push_back(i);
            }
            um[nums[i]] = i;
        }
        return ans;
    }
};