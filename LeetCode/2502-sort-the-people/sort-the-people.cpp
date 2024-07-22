class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> p;
        vector<string> ans;
        int n = names.size();
        for(int i = 0; i < n; i++){
            p.push_back({heights[i], names[i]});
        }

        sort(p.rbegin(), p.rend());

        for(auto it: p){
            ans.push_back(it.second);
        }

        return ans;
    }
};