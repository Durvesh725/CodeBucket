class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> um;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            um[arr[i]]++;
        }
        
        set<int> s;
        for(auto it: um){
            s.insert(it.second);
        }
        
        if(um.size() == s.size())
            return true;
        return false;
    }
};