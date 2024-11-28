class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] != val){
                nums[j] = nums[i];
                j++;
            }
        }
        
        // for(auto it: nums)
        //     cout << it << " ";
        // cout << endl;

        return j;
    }
};