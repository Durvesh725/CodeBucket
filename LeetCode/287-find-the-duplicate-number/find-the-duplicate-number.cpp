class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // set<int> s;
        // int dup = 0;
        // for(auto it: nums){
        //     if(s.find(it) != s.end())
        //         dup = it;
        //     s.insert(it);
        // }
        int n = nums.size();
        while(nums[nums[0]] != nums[0]){
            swap(nums[0],nums[nums[0]]);
        }

        // int bit  = 1;
        // int  n = nums.size();
        // for(int i = 0; i < n ; i++){
        //     bit = bit ^ nums[i];
        // }

       
        
        return nums[0];
    }
};

// 1 2 2 3 4