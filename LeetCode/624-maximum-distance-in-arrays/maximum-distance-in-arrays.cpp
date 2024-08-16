class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int min_till_now = arrays[0][0];
        int max_till_now = arrays[0].back();
        int max_dist = 0;

        for(int i = 1; i < n; i++){
            max_dist = max(max_dist, (abs(min_till_now - arrays[i].back())));
            max_dist = max(max_dist, (abs(max_till_now - arrays[i][0])));
            min_till_now = min(min_till_now, arrays[i][0]);
            max_till_now = max(max_till_now, arrays[i].back());
        }

        return max_dist;
    }
};
// min 1
// max 3
// min