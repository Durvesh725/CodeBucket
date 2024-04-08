class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a){
    stack<int> st;
        
        for(int i = 0; i < a.size(); i++){
            if(a[i] > 0 || st.empty()){
                st.push(a[i]);
            }
            else{
                //current is in left direction && top is in right direction and till top is less than curr, pop(collision)
                while(!st.empty() && st.top() > 0 && st.top() < abs(a[i])){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(a[i])){
                    st.pop();
                }
                else if(st.empty() || st.top() < 0){
                    st.push(a[i]);
                }
            }
        }
        
        vector<int> ans(st.size());
        for(int i = ans.size() - 1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        
        return ans;
    }
};
