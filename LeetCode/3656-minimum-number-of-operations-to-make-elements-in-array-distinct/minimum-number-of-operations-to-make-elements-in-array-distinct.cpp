class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> um;
        for(auto it: nums){
            um[it]++;
        }

        int sz = nums.size();
        if(sz == um.size())
            return 0;
            
        int op = 0;
        int i = 0;
        while(true){
            for(int j = 0; j < 3 && i < nums.size(); j++){
                um[nums[i]]--;
                if(um[nums[i]] == 0){
                    um.erase(nums[i]);
                }
                i++, sz--;
            }
            if(um.size() == sz){
                break;
            }
            op++;
        }
        return op+1;
    }
};