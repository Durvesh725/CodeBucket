class Solution {
public:
    vector<int> asteroidCollision(std::vector<int>& a){
    stack<int> st;
        
        for(int i = 0; i < a.size(); i++){
            if(a[i] > 0 || st.empty() || st.top() < 0){
                st.push(a[i]);
            }
            else{
                while(!st.empty() && st.top() > 0 && st.top() < -a[i]){
                    st.pop();
                }
                if(!st.empty() && st.top() == -a[i]){
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
