class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);
        for(auto edge: roads){
            int u = edge[0];
            int v = edge[1];
            deg[u]++;
            deg[v]++;
        }

        sort(deg.begin(), deg.end());
        long long val = 1, sum = 0;
        for(int i = 0; i < n; i++){
            sum += (deg[i] * val);
            val++;
        }

        return sum;
    }
};