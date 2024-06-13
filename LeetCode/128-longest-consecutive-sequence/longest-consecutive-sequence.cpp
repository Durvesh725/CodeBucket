class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //optimal solution
        unordered_set<int> s;
        int n = nums.size();
        for(auto it: nums){
            s.insert(it);
        }

        int cnt = 1;
        int longest = 0;
        for(auto it: s){
            //see if the curr element is itself the starting point for the consecutive sequence
            if(s.find(it - 1) == s.end()){
                int x = it;
                cnt = 1;
                //if yes, check for further seq
                while(s.find(x + 1) != s.end()){
                    x += 1;
                    cnt++;
                }

                //if no further sequence exists, store the longest len of curr seq
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};

//TC: O(2N) as we are not considering every element as a starting point