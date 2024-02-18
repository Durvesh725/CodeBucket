class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i <= n; i++){
            string prev = ans;
            int plen = ans.size();
            ans = "";
            int j = 0;
            while(j < plen){
                int count = j;
                while(j < plen && prev[j] == prev[count]){
                    count++;
                }
                ans += to_string(count-j) + prev[j];
                j = count;
            }
        }
        return ans;
    }
};