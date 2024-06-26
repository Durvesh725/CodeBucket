class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = 0;
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(count == 0){
                count = 1;
                element = nums[i];
            }
            else if(element == nums[i]){
                count++;
            }
            else
                count--;
        }

        return element;
        //as it says the element is guaranteed
    }
};