class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n);
        int left = 0, right = n-1;
        int i = 0, j = n-1;

        while(i < n && j >= 0){
            if(nums[i] < pivot){
                res[left] = nums[i];
                left++;
            }
            if(nums[j] > pivot){
                res[right] = nums[j];
                right--;
            }
            i++, j--;
        }

        while(left <= right){
            res[left] = pivot;
            left++;
        }

        return res;
    }
};