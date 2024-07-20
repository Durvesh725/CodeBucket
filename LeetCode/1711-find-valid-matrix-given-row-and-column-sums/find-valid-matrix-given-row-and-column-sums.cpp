class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> rs(n, vector<int>(m, 0));
        int i = 0, j = 0;

        while(i < n && j < m){
            rs[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -= rs[i][j];
            colSum[j] -= rs[i][j];

            if(rowSum[i] == 0)  i++;
            if(colSum[j] == 0) j++;
        }

        return rs;
    }
};