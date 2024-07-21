class Solution {
public:
    bool doesAliceWin(string s) {
        int vowels = 0;
        int n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
                vowels++;
        }

        return (vowels > 0) ? true: false;
    }
};