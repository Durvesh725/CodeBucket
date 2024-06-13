class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256, -1);
        int n = s.size();
        int left = 0, right = 0;
        int maxLen = 0;

        while(right < n){
            //seen char before
            if(mp[s[right]] != -1)
                left = max(left, mp[s[right]] + 1);

            mp[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};