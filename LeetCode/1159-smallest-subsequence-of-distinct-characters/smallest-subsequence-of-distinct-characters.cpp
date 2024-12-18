class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        stack<char> st;
        int freq[26] = {0};
        bool check[26] = {false};

        for(char &ch: s){
            freq[ch - 'a']++;
        }

        for(char ch: s){
            freq[ch - 'a']--;
            if(check[ch - 'a'])
                continue;

            while(!st.empty() && st.top() > ch && freq[st.top() - 'a'] > 0){
                check[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            check[ch - 'a'] = true;
        }

        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};