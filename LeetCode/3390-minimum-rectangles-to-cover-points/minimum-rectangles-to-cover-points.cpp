class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        //we need only x cordinated
        int n = points.size();
        int ans = 0;
        sort(points.begin(), points.end());

        for(int i = 0; i < n;){
            int curr = points[i][0];
            int max_end = curr + w;
            ans++;
            while(i < n && points[i][0] <= max_end)
                i++;
        }
        return ans;
    }
};