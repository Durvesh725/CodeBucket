class Solution {
public:
    bool canForm(string &str1, string &sub){
        int n1 = str1.size();
        int n2 = sub.size();

        if(n1 % n2 != 0)
            return false;

        for(int i = 0; i < n1; i++){
            if(str1[i] != sub[i % n2])
                return false;
        }

        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        int gcd = __gcd(str1.size(), str2.size());
        string cand = str1.substr(0, gcd);

        if(canForm(str1, cand) && canForm(str2, cand)) {
            return cand;
        }

        return "";
    }
};