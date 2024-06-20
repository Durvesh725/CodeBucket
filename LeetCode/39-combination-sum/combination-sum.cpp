class Solution {
public:
    void solve(int ind, vector<int>& c, int target, vector<vector<int>> &ans, vector<int> &temp){
        if(ind == c.size()){
            if(target == 0)
                ans.push_back(temp);
            return;
        }

        if(c[ind] <= target){
            temp.push_back(c[ind]);
            solve(ind, c, target - c[ind], ans, temp);
            temp.pop_back();
        }

        solve(ind + 1, c, target, ans, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, c, target, ans, temp);
        return ans;
    }
};