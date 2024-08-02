class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cntOne = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 1)
                cntOne++;
        }

        if(cntOne == n || cntOne == 0)
            return 0;

        int swaps = INT_MAX, cntZ = 0;
        for(int i = 0; i < cntOne; i++){
            if(nums[i] == 0)
                cntZ++;
        }
        swaps = min(swaps, cntZ);

        for(int i = 1; i < n; i++){
            if(nums[i-1] % n == 0)    
                cntZ--;

            if(nums[(i + cntOne - 1) % n] == 0)
                cntZ++;

            swaps = min(swaps, cntZ);            
        }
        return swaps;
    }
};