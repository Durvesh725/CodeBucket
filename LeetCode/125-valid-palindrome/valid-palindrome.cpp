class Solution {
    private:
    bool isValid(char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            return 1;
        }
        return 0;
    }

    char toLowerCase(char ch){
        if((ch>='a' && ch<='z')){
            return ch;
        }
        else{
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }

    bool palindrome(string a){
        int s = 0;
        int e = a.size()-1;

        while(s<e){
            if(a[s] != a[e]){
                return 0;
            }
            else{
                s++;
                e--;
            }
        }
        return 1;
    }
public:
    bool isPalindrome(string s) {
        string temp="";
        //remove useless char and convert to LowerCase
        for(int i=0; i<s.size(); i++){
            if(isValid(s[i])){
                temp.push_back(toLowerCase(s[i]));
            }
        }

        //check Palindrome
        return palindrome(temp);
    }
};