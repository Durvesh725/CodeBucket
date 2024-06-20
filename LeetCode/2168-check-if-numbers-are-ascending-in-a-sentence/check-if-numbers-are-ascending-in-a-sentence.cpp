class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.size();
        int lastNumber = -1;
        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                int num = 0;
                while(i < n && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                if(num <= lastNumber)
                    return false;
                else
                    lastNumber = num;
            }
        }
        return true;
    }
};