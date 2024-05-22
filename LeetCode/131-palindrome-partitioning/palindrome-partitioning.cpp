class Solution {
private:
    bool isPalindrome(int i, int j, string s){
        while(i <= j){
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }

    void solve(int ind, string s,  vector<vector<string>> &ans, vector<string> &path){
        if(ind == s.size()){
            ans.push_back(path);
            return;
        }

        for(int i = ind; i < s.size(); i++){
            if(isPalindrome(ind, i, s)){
                path.push_back(s.substr(ind, i - ind + 1));
                solve(i+1, s, ans, path);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0, s, ans, path);
        return ans;
    }
};