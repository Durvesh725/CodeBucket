class Solution {
public:
    int minimumDeletions(string s) {
        stack<int> st;
        int n = s.size();
        int del = 0;

        for(int i = 0; i < n; i++){
            if(!st.empty() && (st.top() == 'b' && s[i] == 'a')){
                st.pop();
                del++;
            }
            else{
                st.push(s[i]);
            }
        }

        return del;
    }
};