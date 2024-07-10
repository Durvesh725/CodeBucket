class Solution {
public:
    vector<int> findLonely(vector<int>& num) {
        vector<int> ans;
        unordered_map<int, int> nums;
        for(int i: num){
            nums[i]++;
        }

        for(int i: num){
            if(nums[i] == 1 && ((nums.find(i+1) == nums.end()) && (nums.find(i-1) == nums.end()))){
                ans.push_back(i);
            }
        }

        return ans;
    }
};