class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        int n = word.size();
        for(int i = 0; i < n; i++){
            freq[word[i] - 'a']++;
        }

        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());

        int ans = 0;
        for(int i = 0; i < 26; i++){
            int key = i/8 + 1;
            ans += freq[i] * key;
        }

        return ans;
    }
};