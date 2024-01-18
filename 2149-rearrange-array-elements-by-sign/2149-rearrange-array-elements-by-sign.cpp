class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p, n;
        vector<int> ans;
        int x = nums.size();
        for(int i = 0; i < x; i++){
            if(nums[i] < 0)
                n.push_back(nums[i]);
            else
                p.push_back(nums[i]);
        }
        
        int y = p.size();
        for(int i = 0; i < y; i++){
            ans.push_back(p[i]);
            ans.push_back(n[i]);
        }
        return ans;
    }
};