class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        int n = s.size();

        for(int i = 0; i < n; i++){
            num.append(to_string(s[i] - 'a' + 1));
        }

        int sum = 0;
        while(k){
            sum = 0;
            for(int i = 0; i < num.size(); i++){
                sum += (num[i] - '0');
            }
            num = to_string(sum);
            k--;
        }

        return sum;
    }
};