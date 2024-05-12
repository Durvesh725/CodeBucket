class Solution {
private:
    int findMaxLocal(int row, int col, vector<vector<int>>& grid){
        int maxi = INT_MIN;
        for(int i = row; i <= row + 3 - 1; i++){
            for(int j = col; j <= col + 3 - 1; j++){
                maxi = max(maxi, grid[i][j]);
            }
        }
        return maxi;
    }

public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
       int n = grid.size();
       vector<vector<int>> ans(n-2, vector<int>(n-2));
       for(int k = 0; k <= n - 3; k++){
        for(int l = 0; l <= n - 3; l++){
            ans[k][l] = findMaxLocal(k, l, grid);
        }
       }

       return ans;
    }
};