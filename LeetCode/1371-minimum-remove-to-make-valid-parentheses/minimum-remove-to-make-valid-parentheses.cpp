class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int ps_o = 0, ps_c = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                ps_o++;
            }
            else if(s[i] == ')'){
                ps_c++;
                if(ps_c > ps_o){
                    s.erase(i, 1);
                    ps_c--;
                    i--;
                }
            }
        }

        ps_o = 0;
        ps_c = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == ')') {
                ps_c++;
            } 
            else if(s[i] == '(') {
                ps_o++;
                if(ps_o > ps_c) {
                    s.erase(i, 1);
                    ps_o--;
                }
            }
        }

        return s;
    }
};