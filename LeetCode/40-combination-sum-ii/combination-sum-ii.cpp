class Solution {
public:
    void solve(int ind, vector<int>& c, int t, vector<vector<int>> &ans, vector<int> &temp){
        if(t == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = ind; i < c.size(); i++){
            if(i > ind && c[i] == c[i-1])   continue;

            if(c[i] > t)
                break;

            temp.push_back(c[i]);
            solve(i+1, c, t - c[i], ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(), c.end());
        vector<vector<int>> ans;
        vector<int> temp; 
        solve(0, c, t, ans, temp);
        return ans;
    }
};