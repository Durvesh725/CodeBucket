class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st;

        for(int i = 0; i < n; i++){
            int mul = arr[i] * 2;
            if(st.find(mul) != st.end()){
                return true;
            }

            if(arr[i]%2 == 0 && st.find(arr[i]/2) != st.end()){
                return true;
            }

            st.insert(arr[i]);
        }

        return false;
    }
};