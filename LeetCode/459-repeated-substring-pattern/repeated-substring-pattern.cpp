class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        int len = 0, i = 1;
        vector<int> lps(n, 0);
        while(i < n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0)
                    len = lps[len - 1];
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int lps_len = lps[n-1];
        if(lps_len > 0 && n % (n-lps_len) == 0)
            return true;
        return false;
    }
};