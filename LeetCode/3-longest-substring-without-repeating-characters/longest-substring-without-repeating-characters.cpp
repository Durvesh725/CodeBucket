class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;

        for(int i = 0; i < n; i++){
            int hash[128] = {0};
            for(int j = i; j < n; j++){
                if(hash[s[j]] == 1) break;
                maxLen = max(maxLen, j - i + 1);

                hash[s[j]] = 1;
            }
        }

        return maxLen;
    }
};