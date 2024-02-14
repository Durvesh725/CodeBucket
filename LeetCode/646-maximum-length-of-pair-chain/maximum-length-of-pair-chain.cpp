class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // GREEDY
        sort(pairs.begin(), pairs.end());
        int ans = 0;
        int n = pairs.size();
        int startLimit = INT_MAX;
        for(int i = n-1; i >= 0; i--){
            if(pairs[i][1] < startLimit){
                ans++;
                startLimit = pairs[i][0];
            }
        }
        return ans;    
    }
};