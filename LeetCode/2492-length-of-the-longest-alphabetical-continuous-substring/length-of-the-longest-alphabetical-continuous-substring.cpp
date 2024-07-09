class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int ans = 0;
        
        while(right < n){
            //if char are exactly cons, there diff will always be 1
            if(right + 1 < n && s[right] == s[right+1] - 1){
                right++;
            }
            else{
                right++;
                left = right;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};