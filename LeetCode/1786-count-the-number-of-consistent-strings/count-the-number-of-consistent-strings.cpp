class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;

        for(char &ch: allowed){
            st.insert(ch);
        }

        int count = 0;
        for(auto it: words){
            string s = it;
            bool f = true;

            for(char &ch: s){
                if(st.find(ch) == st.end()){
                    f = false;
                }
            }

            if(f)
                count++;
        }

        return count;
    }
};