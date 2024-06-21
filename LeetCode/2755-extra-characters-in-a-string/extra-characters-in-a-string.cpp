class Solution {
public:
    unordered_set<string> st;
    int n;

    int solve(int ind, string &s, vector<int> &dp){
        if(ind >= n)
            return 0;

        if(dp[ind] != -1)
            return dp[ind];

        string temp = "";
        int minExtra = n;

        for(int i = ind; i < n; i++){
            temp.push_back(s[i]);
            //if the string doesnt exist in the set, obv it is possibly extra char, o/w it exists so ret 0
            int currExtra = (st.find(temp) == st.end()) ? temp.size() : 0;
            int remainExtra = solve(i + 1, s, dp);
            int totalExtra = currExtra + remainExtra;
            minExtra = min(minExtra, totalExtra);
        }
        return dp[ind] = minExtra;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.size();
        for(string &word: dictionary)
            st.insert(word);

        vector<int> dp(n+1, -1);
        return solve(0, s, dp);      
    }
};