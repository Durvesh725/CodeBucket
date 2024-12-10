class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.empty())
            return 0;

        int n = s.size();
        unordered_map<char, int> um;

        for(char c: s){
            um[c]++;
        }

        for(int i = 0; i < n; i++){
            if(um[s[i]] < k){
                // cout << s.substr(0, i) << endl;
                int left = longestSubstring(s.substr(0, i), k);
                // cout << s.substr(i+1) << endl;
                int right = longestSubstring(s.substr(i+1), k);
                // cout << max(left, right) << endl;
                return max(left, right);
            }
        }  

        return s.size();
    }
};