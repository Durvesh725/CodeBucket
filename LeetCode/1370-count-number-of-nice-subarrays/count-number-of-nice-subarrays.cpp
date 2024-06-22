class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> newNums(n, 0);
        for(int i = 0; i < n; i++){
            if(nums[i]&1)
                newNums[i] = 1;
        }

        unordered_map<int, int> um;
        int ps = 0, subarray = 0;
        um[0] = 1;
        for(int &num: newNums){
            ps += num;
            int remove = ps - k;
            if(remove >= 0)
                subarray += um[remove];
            um[ps]++;
        }
        
        return subarray;
    }
};