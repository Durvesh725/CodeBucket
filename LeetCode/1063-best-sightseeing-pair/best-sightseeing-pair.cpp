class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int maxPair1 = values[0];
        int ans = INT_MIN;

        for(int i = 1; i < n; i++){
            if(values[i] - i + maxPair1 > ans)
                ans = values[i] - i + maxPair1;

            if(values[i] + i > maxPair1)
                maxPair1 = values[i] + i;
        }

        return ans;
    }
};