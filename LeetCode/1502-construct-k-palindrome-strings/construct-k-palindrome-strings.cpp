class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.size())
            return false;

        unordered_map<char, int> um;
        for(char &ch: s){
            um[ch]++;
        }

        int oc = 0;
        for(auto it: um){
            if(it.second&1) oc++;
        }

        if(oc > k)
            return false;
        
        return true;
    }
};