class Solution {
public:
    bool isPalindrome(int i, int j, string &s){
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++, j--;
        }
        return true;
    }

    void solve(int ind, string s, vector<vector<string>> &ans, vector<string> temp){
        if(ind == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = ind; i < s.size(); i++){
            if(isPalindrome(ind, i, s)){
                temp.push_back(s.substr(ind, i - ind + 1));
                solve(i + 1, s, ans, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s, ans, temp);
        return ans;
    }
};