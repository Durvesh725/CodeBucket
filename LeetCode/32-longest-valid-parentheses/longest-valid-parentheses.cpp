class Solution {
public:
    int longestValidParentheses(string str) {
        int n = str.length();
        stack<int> st;
        st.push(-1);
        int maxLen = 0;
        
        for(int i = 0; i < n; i++){
            if(str[i] == '(')
                st.push(i);
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        
        return maxLen;
    }
};