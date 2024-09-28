class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int evenInd = 0;
        int oddInd = 1;
        int n = nums.size();

        while(evenInd < n && oddInd < n){
            if(nums[evenInd] % 2 == 0){
                evenInd += 2;
            }
            else if(nums[oddInd] % 2 == 1){
                oddInd += 2;
            }
            else{
                swap(nums[evenInd], nums[oddInd]);
                evenInd += 2;
                oddInd += 2;
            }
        }

        return nums;   
    }
};