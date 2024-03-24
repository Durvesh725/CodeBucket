class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> s;
        int dup = 0;
        for(auto it: nums){
            if(s.find(it) != s.end())
                dup = it;
            s.insert(it);
        }
        return dup;
    }
};

// 1 2 2 3 4