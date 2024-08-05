class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> um1;
        unordered_map<string, int> um2;
        vector<string> temp;
        int cnt = 0;

        for(string &str: words1){
            um1[str]++;
        }

        for(string &str: words2){
            um2[str]++;
        }

        for(auto it: um1){
            if(it.second == 1){
                if(um2[it.first] == 1){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};