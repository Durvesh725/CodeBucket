class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string, int> um1;
        unordered_map<string, int> um2;
        int count = 0;

        for(string &s: message){
            um1[s]++;
        }
        for(string &s: bannedWords){
            um2[s]++;
        }

        for(auto it: um1){
            if(um2.find(it.first) != um2.end()){
                count += it.second;
            }
        }

        return (count >= 2);
    }
};