class Solution {
private:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A'|| ch == 'E'|| ch == 'I'|| ch == 'O'|| ch == 'U'){
            return true;
        }
        return false;
    }
    
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int c1 = 0;
        int c2 = 0;
        int mid = n/2;
        for(int i = 0; i < mid; i++){
            if(isVowel(s[i])){
                c1++;
            }
        }
        
        for(int i = mid; i < n; i++){
            if(isVowel(s[i])){
                c2++;
            }
        }
        
        if(c1 == c2){
            return true;
        }
        return false;
    }
};