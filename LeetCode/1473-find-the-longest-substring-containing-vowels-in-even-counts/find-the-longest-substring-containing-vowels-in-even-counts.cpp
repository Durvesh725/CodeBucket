class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> um;
        int mask = 0;
        int n = s.size();
        int len = 0;
        um[mask] = -1;

        for(int i = 0; i < n; i++){
            if(s[i] == 'a')
                mask = mask ^ (1 << 0);
            else if(s[i] == 'e')
                mask = mask ^ (1 << 1);
            else if(s[i] == 'i')
                mask = mask ^ (1 << 2);
            else if(s[i] == 'o')
                mask = mask ^ (1 << 3);
            else if(s[i] == 'u')
                mask = mask ^ (1 << 4);

            if(um.find(mask) != um.end()){
                len = max(len, i - um[mask]);
            }
            else{
                um[mask] = i;
            }
        }

        return len;
    }
};