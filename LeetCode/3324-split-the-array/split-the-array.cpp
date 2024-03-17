class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> um;
        for(auto it: nums){
            um[it]++;
            if(um[it] > 2)
                return false;
        }
        return true;
    }
};