class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> d;
        for(int i = 0; i < nums.size(); i++){
            if(d.find(nums[i]) == d.end())
                d.insert(nums[i]);
            else
                return true;
        }
        return false;
    }
};