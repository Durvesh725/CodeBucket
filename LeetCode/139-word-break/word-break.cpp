class Solution {
public:
    unordered_set<string> st;
    int n;

    bool solve(int ind, string s, vector<int> &dp){
        if(ind == n)
            return true;

        if(st.find(s.substr(ind , n - ind)) != st.end()) {
            return true;
        }

        if(dp[ind] != -1)
            return dp[ind];

        for(int len = 1; len < s.size(); len++){
            string temp = s.substr(ind, len);
            // cout << temp << endl;
            if(st.find(temp) != st.end() && solve(ind + len, s, dp))
                return dp[ind] = true;
        }

        return dp[ind] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        for(string &word: wordDict){
            st.insert(word);
        }
           
        vector<int> dp(n+1, -1);
        return solve(0, s, dp);

    }
};