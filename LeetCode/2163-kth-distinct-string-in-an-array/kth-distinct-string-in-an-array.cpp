class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> um;
        vector<string> ans;

        for(auto it: arr){
            um[it]++;
        }

        for(auto it: arr){
            if(um[it] == 1){
                ans.push_back(it);
            }
        }

        if(k <= ans.size())
            return ans[k-1];

        return "";
    }
};