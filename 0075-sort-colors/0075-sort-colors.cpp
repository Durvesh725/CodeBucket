class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cz = 0, c1 = 0, c2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0)
                cz++;
            if(nums[i] == 1)
                c1++;
            if(nums[i] == 2)
                c2++;        
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(cz > 0){
                nums[i] = 0;
                cz--;
            }
            else if(c1 > 0){
                nums[i] = 1;
                c1--;
            }
            else{
                nums[i] = 2;
            }
        }
    }
};