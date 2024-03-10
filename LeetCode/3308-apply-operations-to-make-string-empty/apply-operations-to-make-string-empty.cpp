class Solution {
public:
    string lastNonEmptyString(string s) {
        unordered_map<char, int> freq;
        int maxF = 0;
        for(int i = 0; i < s.size(); i++){
            freq[s[i]]++;
            maxF = max(maxF, freq[s[i]]);
        }

        string ans = "";
        unordered_map<char, int> currF;
        for(int i = 0; i < s.size(); i++){
            currF[s[i]]++;
            if(currF[s[i]] == maxF)
                ans+=s[i];
        }
        return ans;
    }
};