class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(st.empty())
                    return false;

                char ch = s[i];
                if((st.top() == '(' && ch == ')') || (st.top() == '{' && ch == '}') || 
                (st.top() == '[' && ch == ']')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }

        return st.empty();
    }
};