class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        const int maxi = *max_element(nums.begin(), nums.end());
        int freq = 0;
        long long ans = 0;
        int j = 0, i = 0;
        while(j < nums.size()){
            if(nums[j] == maxi)
                freq++;
            while(freq >= k){
                ans += (nums.size()-j);
                if(nums[i] == maxi)
                    freq--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
