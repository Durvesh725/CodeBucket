class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s;
        for(auto it: candyType){
            s.insert(it);
        }

        if(s.size() > (candyType.size() >> 1))
            return (candyType.size() >> 1);
        
        return s.size();
    }
};