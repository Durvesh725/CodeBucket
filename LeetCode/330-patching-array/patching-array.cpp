class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int nums_len = nums.size();
        long long maxNo = 0;
        int i = 0, no_of_patch = 0;
        while(maxNo < n){
            if(i < nums_len && maxNo + 1 >= nums[i]){
                maxNo += nums[i];
                i++;
            }
            else{
                no_of_patch++;
                maxNo += (maxNo + 1);
            }
        }

        return no_of_patch;
    }
};