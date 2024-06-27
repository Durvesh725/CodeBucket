class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        set<int> st;
        for(int i = 0; i < edges.size(); i++){
            if(st.find(edges[i][0]) != st.end()){
                return edges[i][0];
            }
            if(st.find(edges[i][1]) != st.end()){
                return edges[i][1];
            }
            st.insert(edges[i][0]);
            st.insert(edges[i][1]);
        }
        return -1;
    }
};