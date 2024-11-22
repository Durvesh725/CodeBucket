class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<string, int> um;
        int maxi = 0;

        for(int i = 0; i < n; i++){
            string org = "";
            string flipped = "";
            for(int j = 0; j < m; j++){
                org += to_string(matrix[i][j]);
                flipped += to_string(1 - matrix[i][j]);
            }

            um[org]++;
            um[flipped]++;
        }

        for(auto &[pattern, cnt] : um){
            maxi = max(maxi, cnt);
        }

        return maxi; 
    }
};