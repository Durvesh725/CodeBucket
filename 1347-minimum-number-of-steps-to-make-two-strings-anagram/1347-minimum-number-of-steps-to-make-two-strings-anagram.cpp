class Solution {
public:
    int minSteps(string s, string t) {
        //stpre frequency
        unordered_map<char, int> um;
        for(int i = 0; i < s.size(); i++){
            //neutralize i.e same characters gets cut down
            um[s[i]]++;
            um[t[i]]--;
        }
        
        
        //take only positive differences
        int ans = 0;
        for(auto i: um){
            if(i.second > 0){
                ans+=i.second;
            }
        }
        return ans;
    }
};