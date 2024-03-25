class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k != 0 )
            return false;
        else{
            unordered_map<int, int> um;
            for(int i = 0; i < nums.size(); i++)
                um[nums[i]]++;

            sort(nums.begin(), nums.end());

            for(int i = 0; i < nums.size(); i++){
                if(um[nums[i]] == 0)
                    continue;

                for(int j = 0; j < k; j++){
                    int curr = nums[i] + j;

                    if(um[curr] == 0)
                        return false;

                    um[curr]--;
                }
            }
        }
        return true;
    }
};