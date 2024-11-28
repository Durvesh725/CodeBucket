class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        stack<string> st;

        while(ss >> word){
            st.push(word);
        }

        string res = "";
        while(!st.empty()){
            res += st.top() + " ";
            st.pop();
        }

        if(res != ""){
            res.pop_back();
        }

        return res;
    }
};