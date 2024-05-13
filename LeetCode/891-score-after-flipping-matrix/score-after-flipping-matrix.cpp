class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> res(n, vector<int>(n, -1));

        //if grid[0][0] is 0 filp entire row
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 0){
                for(int j = 0; j < m; j++)
                    grid[i][j] ^= 1;
            }
        }  

        //go through all col, find count of 1s, if 1s < 0s, then optimal to flip
        for(int j = 1; j < m; j++){
            int one_count = 0;
            for(int i = 0; i < n; i++){
                one_count += grid[i][j];
            }

            if(one_count < n - one_count){
                for(int i = 0; i < n; i++){
                    grid[i][j] ^= 1;
                }
            }
        }

        //final res
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans += grid[i][j] * (1 << (m - j - 1));
            }
        }

        return ans;
    }
};