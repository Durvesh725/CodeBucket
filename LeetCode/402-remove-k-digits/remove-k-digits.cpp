class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();

        if(k >= n)  return "0";

        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top() > num[i] && k > 0){
                st.pop();
                k--;
            }
            st.push(num[i]);
            if(st.size()==1 && st.top()=='0') st.pop();
        }

        //even after whole traversal, k remains, then delete last k digits
        //TC: 1,4,3,2,7,8
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }

        //after k removals if stack becomes empty
        if(st.empty())   return "0";

        string ans;      
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;
        while(i < ans.size() && ans[i] == '0')
            i++;

        return (ans.empty()) ? "0" : ans.substr(i);
    }
};
