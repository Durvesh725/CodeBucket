class Solution {
public:
    string getSmallestString(string s, int k) {
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            int leftD = s[i] - 'a';
            int rightD = ('z' - s[i]) + 1;
            int minD = min(leftD, rightD);
            if(minD <= k){
                ans += 'a';
                k -= minD;
            }
            else{
                char c = s[i] - k;
                ans += c;
                k = 0;
            }
        }
        return ans;
    }
};