class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            if(number[i] == digit){
                string s = number.substr(0, i) + number.substr(i+1);
                ans = max(ans, s);
            }
        }
        return ans;
    }
};