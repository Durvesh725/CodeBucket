class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++){
            while(!st.empty() && prices[st.top()] >= prices[i]){
                int ind = st.top();
                ans[ind] = prices[ind] - prices[i];
                st.pop();
            }

            st.push(i);
        }

        while(!st.empty()){
            int ind = st.top();
            ans[ind] = prices[ind];
            st.pop();
        }

        return ans;
    }
};