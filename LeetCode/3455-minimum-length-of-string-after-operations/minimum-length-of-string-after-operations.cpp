class Solution {
public:
    int minimumLength(string s) {
        unordered_map<int, int> mp;
        int ans = s.length();
        for(char &ch: s){
            mp[ch]++;
            if(mp[ch] == 3){
                mp[ch] -= 2;
                ans -= 2;
            }
        }
        return ans;
    }
};

//upsolved