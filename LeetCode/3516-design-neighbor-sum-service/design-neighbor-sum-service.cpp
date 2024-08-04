class neighborSum {
public:
    vector<vector<int>> grid;
    int n;

    neighborSum(vector<vector<int>>& g) {
        grid = g;
        n = g.size();
    }
    
    pair<int, int> getOriginalRowCol(int val){
        int org_row = 0;
        int org_col = 0;
        int n = grid.size();
        int m = grid[0].size();
        bool found = false;
        for(int i = 0; i < n && !found; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == val){
                    org_row = i;
                    org_col = j;
                    found = true;
                    break;
                }
            }
        }

        return {org_row, org_col};
    }

    int adjacentSum(int value) {
        int row[4] = {-1, 0, 1, 0};
        int col[4] = {0, 1, 0, -1};
        int adj_sum = 0;
        int org_row = getOriginalRowCol(value).first;
        int org_col = getOriginalRowCol(value).second;

        for(int i = 0; i < 4; i++){
            int n_row = row[i] + org_row;
            int n_col = col[i] + org_col;

            if(n_row >= 0 && n_row < n && n_col >= 0 && n_col < n){
                adj_sum += grid[n_row][n_col];
            }
        }

        return adj_sum;
    }
    
    int diagonalSum(int value) {
        int row[4] = {-1, 1, 1, -1};
        int col[4] = {1, 1, -1, -1};
        int dia_sum = 0;
        int org_row = getOriginalRowCol(value).first;
        int org_col = getOriginalRowCol(value).second;

        for(int i = 0; i < 4; i++){
            int n_row = row[i] + org_row;
            int n_col = col[i] + org_col;

            if(n_row >= 0 && n_row < n && n_col >= 0 && n_col < n){
                dia_sum += grid[n_row][n_col];
            }
        }

        return dia_sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */