class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        for(char ch: s){
            if(ch == '('){
                st.push('(');
            }
            else if(ch == ')'){
                string temp = "";
                while(st.top() != '('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();

                for(auto ch: temp) st.push(ch);
            }
            else{
                st.push(ch);
            }
        }

        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};