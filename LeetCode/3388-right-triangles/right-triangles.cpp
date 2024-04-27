class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long m = grid[0].size();
        vector<long long> r(n),c(m);
        long long ans = 0;

        for(int i = 0; i< n; ++i){
            int cnt = 0;
            for(int j = 0; j < m; j++){
                cnt += (grid[i][j] == 1);
            }
            r[i] = cnt;
        }
        for(int j = 0; j < m; ++j){
            int cnt = 0;
            for(int i = 0; i < n; i++){
                cnt += (grid[i][j] == 1);
            }
            c[j] = cnt;
        }

        for(int i = 0; i< n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1){
                    int col = c[j];
                    int row = r[i];

                    col--;
                    row--;
                    ans += (row * col);
                }
            }
        }

        return ans;
    }
};