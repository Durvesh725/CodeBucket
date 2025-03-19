class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> um;
        int n = nums.size();

        for(int i = 1; i < n; i++){
            if(nums[i-1] == key){
                um[nums[i]]++;
            }
        }

        int ans = INT_MIN;
        int maxi = INT_MIN; 
        for(auto it: um){
            if(it.second > maxi){
                maxi = it.second;
                ans = it.first;
            }
        }

        return ans;
    }
};