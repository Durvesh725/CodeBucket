class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //using moore's voting algo
        int ele = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            //update the ele as per algo
            if(cnt == 0){
                cnt = 1;
                ele = nums[i];
            }
            else if(ele == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        //we dont need to verify again because the problem itself states there exists a majority ele
        return ele;
    }
};