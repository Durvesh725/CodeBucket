class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        istringstream stream1(s1);
        istringstream stream2(s2);
        unordered_map<string, int> um1;
        unordered_map<string, int> um2;
        vector<string> ans;

        string word = "";
        while(stream1 >> word){
            um1[word]++;
        }

        word = "";
        while(stream2 >> word){
            um2[word]++;
        }

        for(auto it: um1){
            if(um2.find(it.first) == um2.end()){
                if(it.second == 1){
                    ans.push_back(it.first);
                }
            }
        }

        for(auto it: um2){
            if(um1.find(it.first) == um1.end()){
                if(it.second == 1){
                    ans.push_back(it.first);
                }
            }
        }

        return ans;

    }
};