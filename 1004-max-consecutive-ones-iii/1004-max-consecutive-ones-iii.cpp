class Solution {
public:
    int longestOnes(vector<int>& s, int k) {
        int i = 0, j = 0;
        int n = s.size();
        int zc = 0;
        int ans = 0;
        while(j < n){
            if(s[j] == 0){
                zc++;
            }
            while(zc > k){
                if(s[i] == 0){
                    zc--;
                }
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};