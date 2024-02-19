class Solution {
public:
    int minAddToMakeValid(std::string s) {
        std::stack<char> st;
        int cnt = 0;
        for(char ch : s) {
            if(ch == '(') {
                st.push(ch);
            } else if(ch == ')') {
                if(st.empty()) {
                    cnt++;
                } else {
                    st.pop(); 
                }
            }
        }
        return cnt + st.size();
    }
};
