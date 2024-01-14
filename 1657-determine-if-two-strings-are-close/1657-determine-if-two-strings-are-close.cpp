class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> um1, um2;
        for(int i = 0; i < word1.size(); i++){
            um1[word1[i]]++;
        }
        
        for(int i = 0; i < word2.size(); i++){
            um2[word2[i]]++;
        }
        
        //check if all elements in word1 are present in word2, if not directly return
        for(auto it: um1){
            if(um2.find(it.first) == um2.end()){
                return false;
            }
        }
        
        //store frequencies in vec
        vector<int> v1, v2;
        for(auto it: um1){
            v1.push_back(it.second);
        }
        
        for(auto it: um2){
            v2.push_back(it.second);
        }
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        return v1 == v2;
    }
};