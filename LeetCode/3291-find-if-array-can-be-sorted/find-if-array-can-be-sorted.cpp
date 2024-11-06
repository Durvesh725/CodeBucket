class Solution {
public:
    int count(int n){
        int cnt = 0;
        while(n){
            cnt += n & 1;
            n >>= 1;
        }
        return cnt;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        for(int i = n-1; i >= 1; i--){
            bool isSwapped = false;
            for(int j = 0; j < i; j++){
                if(nums[j] > nums[j+1]){
                    if(count(nums[j]) == count(nums[j+1])){
                        swap(nums[j], nums[j+1]);
                        isSwapped = true;
                    }
                    else{
                        return false;
                    }
                }
            }

            if(isSwapped == false)
                break;
        }

        return true;
    }
};