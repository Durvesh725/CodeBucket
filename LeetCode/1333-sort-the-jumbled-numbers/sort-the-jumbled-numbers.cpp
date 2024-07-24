class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> ans;

        vector<pair<int, int>> mp;
        for(int n: nums){
            string s = to_string(n);
            int mapped_val = 0;
            for(char ch: s){
                mapped_val = mapped_val * 10 + mapping[ch - '0'];
            }
            mp.push_back({mapped_val, n});
        }

        sort(mp.begin(), mp.end(), [&](pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first;
        });

        for(auto it: mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};