class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int curr_cost = 0;
        int left = 0;
        int maxLen = 0;

        //expand
        for(int right = 0; right < n; right++){
            curr_cost += abs(s[right] - t[right]);

            //shrink
            while(curr_cost > maxCost){
                curr_cost -= abs(s[left] - t[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};