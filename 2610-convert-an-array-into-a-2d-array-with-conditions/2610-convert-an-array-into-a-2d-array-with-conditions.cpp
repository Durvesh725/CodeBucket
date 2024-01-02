class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        //find max occ of any element
        int maxOcc = 0;
        map<int, int> mp;
        for(auto i: nums){
            mp[i]++;
            maxOcc = max(maxOcc, mp[i]);
        }
        
        
        vector<vector<int>> ans(maxOcc);
        vector<set<int>> s(maxOcc);
        //iterate over original arr
        for(auto x: nums){
            //iterate over each set in a vector
            for(int i = 0; i < maxOcc; i++){
                if(s[i].find(x) == s[i].end()){
                    ans[i].push_back(x);
                    s[i].insert(x);
                    break;
                }
            }
        }
        return ans;
    }
};