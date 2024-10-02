class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        
        if(n == 0) {
            return {}; 
        }

        vector<int> temp = arr;
        sort(arr.begin(), arr.end());

        unordered_map<int, int> rankMap;
        int rank = 1;

        for(int i = 0; i < n; i++) {
            if(rankMap.find(arr[i]) == rankMap.end()) {
                rankMap[arr[i]] = rank++;
            }
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = rankMap[temp[i]];
        }

        return ans;
    }
};
