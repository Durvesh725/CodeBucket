class Solution {
public:
    int findPairs(int dist, vector<int>& nums){
        int n = nums.size();
        int l = 0;
        int r = 0;
        int p = 0;
        for(int r = 0; r < n; r++){
            while(nums[r] - nums[l] > dist) l++;
            p += r - l;
        }
        return p;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = *max_element(nums.begin(), nums.end());

        while(left < right){
            int mid = (left + right)/2;
            int pairs = findPairs(mid, nums);
            if(pairs >= k){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }   

        return left;
    }
};